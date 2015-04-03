#include "cyape.h"
//Generated with genfile -c main.c -i "cyape.h"


int main(){
	
	int hasChanged = 0;
	char * a_list[3];
	
	a_list[0] = "assets/ui/background.png";
	a_list[1] = "assets/world/Alien.png";
	a_list[2] = "assets/world/block.png";
	
	yape_texture texture_list[10];
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Couldn't Initialize SDL!\n");
		exit(-1);
    	}
	SDL_Event event;
    	yape_window window = {
		.name = "Cyape 1.1",
		.done = 0,
		.size = {
			.x = 0, .y = 0, .w = 800, .h = 600,
		},
	};
	window.window = SDL_CreateWindow(
		window.name,
		window.size.x, window.size.y,
		window.size.w, window.size.h,
		SDL_WINDOW_SHOWN
	);
	window.rnd = SDL_CreateRenderer(
		window.window,
		1, 
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	TTF_Init();
	TTF_Font * font = TTF_OpenFont("main.ttf",20);

	//load_textures(a_list,2,&texture_list,window.rnd);
	texture_list[0] = yape_load_texture(a_list[0],window.rnd);
	texture_list[1] = yape_load_texture(a_list[1],window.rnd);
	texture_list[2] = yape_load_texture(a_list[2],window.rnd);

	yape_texture * background = &texture_list[0];
	yape_texture * sprite = &texture_list[1];
		sprite->size.x = 50;
		sprite->size.y = 50;
	yape_texture * block = &texture_list[2];
		block->size.x = 50;
		block->size.y = 50;
	yape_texture sprite_back = *sprite;
	
	SDL_Color color = {0,0,0,0};	
	yape_label test = yape_make_label("Hello I am a Font!", font, 20, 20, color, window.rnd);

    	while(window.done != 1){
		while(SDL_PollEvent(&event) != 0){
			if(event.type == SDL_QUIT){
				window.done = 1;
			}
			if(event.type == SDL_KEYDOWN ){
				switch(event.key.keysym.sym){
					case SDLK_SPACE:
						if(hasChanged == 0){
							sprite->image = block->image;
							hasChanged = 1;
							puts("Sprite Changed to block");
							break;
						}
						if(hasChanged == 1){
							sprite->image = sprite_back.image;
							hasChanged = 0;
							puts("Sprite changed back to sprite");
							break;
						}
						break;
					case SDLK_w:
						sprite->size.y -= 20;
						break;
					case SDLK_s:
						sprite->size.y += 20;
						break;
					case SDLK_a:
						sprite->size.x -= 20;
						break;
					case SDLK_d:
						sprite->size.x += 20;
						break;
					case SDLK_q:
						window.done = 1;
						break;
				}
			}
			if(event.type == SDL_KEYUP ) {
				switch(event.key.keysym.sym) {
					case SDLK_w:
						sprite->size.y += 20;
						break;
					case SDLK_s:
						sprite->size.y -= 20;
						break;
					case SDLK_a:
						sprite->size.x += 20;
						break;
					case SDLK_d:
						sprite->size.x -= 20;
						break;
				}
			}
		}
		SDL_RenderClear(window.rnd);
		SDL_RenderCopy(window.rnd,background->image,NULL,&background->size);
		SDL_RenderCopy(window.rnd,test.image, NULL, &test.size);
		SDL_RenderCopy(window.rnd,sprite->image,NULL,&sprite->size);
		SDL_RenderPresent(window.rnd);
	}
	TTF_CloseFont(font);
	TTF_Quit();
    	SDL_DestroyRenderer(window.rnd);
    	SDL_DestroyWindow(window.window);
    	SDL_Quit();
    	return 0;
}
