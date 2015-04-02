#include "cyape.h"
//Generated with genfile -c main.c -i "cyape.h"


int main(int argc, char * argv[]){
	
	int loaded_tex = 0, total_tex = 2, hasChanged = 0;
	char * tex_list[3];
	
	tex_list[0] = "assets/ui/background.png";
	tex_list[1] = "assets/world/Alien.png";
	tex_list[2] = "assets/world/block.png";
	
	struct Texture * texture_list[20];
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Couldn't Initialize SDL!\n");
		exit(-1);
    	}
	SDL_Event event;
    	struct Window window = {
		.title = "Cyape 1.1",
		.done = 0,
		.size = {
			.x = 0, .y = 0, .w = 800, .h = 600,
		},
	};
	window.window = SDL_CreateWindow(
		window.title,
		window.size.x, window.size.y,
		window.size.w, window.size.h,
		SDL_WINDOW_SHOWN
	);
	window.rnd = SDL_CreateRenderer(
		window.window,
		1, 
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	for(loaded_tex = 0; loaded_tex != total_tex; loaded_tex++){
		SDL_Surface * tmp = IMG_Load(tex_list[loaded_tex]);
		printf("Debug: Loading \"%s\" \n",tex_list[loaded_tex]);
		if(tmp == NULL){
			printf("Unable to load \"%s\"\n",tex_list[loaded_tex]);
			exit(-2);
		}
		struct Texture * tmp_tex_struct = (struct Texture *)malloc(sizeof(struct Texture));
		tmp_tex_struct->image = SDL_CreateTextureFromSurface(window.rnd,tmp);
		tmp_tex_struct->size.h = tmp->h;
		tmp_tex_struct->size.w = tmp->w;
		tmp_tex_struct->tex_name = (char *)malloc(sizeof(char *));
		tmp_tex_struct->tex_name = tex_list[loaded_tex];
		texture_list[loaded_tex] = &(*tmp_tex_struct);
		SDL_FreeSurface(tmp);
	}
	struct Texture * background = texture_list[0];
	struct Texture * sprite = texture_list[1];
	sprite->size.x = 50;
	sprite->size.y = 50;
	struct Texture * block = texture_list[2];
	block->size.x = 50;
	block->size.y = 50;
	SDL_Texture ** sprite_img = &sprite->image;
    	while(window.done != 1){
		while(SDL_PollEvent(&event) != 0){
			if(event.type == SDL_QUIT){
				window.done = 1;
			}
			if(event.type == SDL_KEYDOWN && event.key.repeat == 0){
				switch(event.key.keysym.sym){
					case SDLK_SPACE:
						if(hasChanged == 0){
							sprite->image = block->image;
							hasChanged = 1;
						} else if (hasChanged == 1){
							sprite->image = *sprite_img;
							hasChanged = 0;
						}
						break;
					case SDLK_w:
						sprite->size.y--;
						break;
					case SDLK_s:
						sprite->size.y++;
						break;
					case SDLK_a:
						sprite->size.x--;
						break;
					case SDLK_d:
						sprite->size.x++;
						break;
					case SDLK_q:
						window.done = 1;
						break;
				}
			}
		}
		SDL_RenderClear(window.rnd);
		SDL_RenderCopy(window.rnd,background->image,NULL,&background->size);
		SDL_RenderCopy(window.rnd,sprite->image,NULL,&sprite->size);
		SDL_RenderPresent(window.rnd);
	}
    	SDL_DestroyRenderer(window.rnd);
    	SDL_DestroyWindow(window.window);
    	SDL_Quit();
    	return 0;
}
