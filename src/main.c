#include <cyape.h>
//Generated with genfile -c main.c -i "cyape.h"


int main(int argc, char * argv[]){
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		printf("Couldn't Initialize SDL!\n");
		exit(-1);
    	}
	SDL_Event event;
    	Window window = createWindow("cyape - 1.0", 0,0,800,600);
    	window.done = 0;
    	window.rnd = SDL_CreateRenderer(window.window,1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Texture background = createTexture("assets/ui/background.png",0,0,&window.rnd);
	Texture sprite = createTexture("assets/world/Alien.png",400,300,&window.rnd);
    	while(window.done != 1){
		while(SDL_PollEvent(&event) != 0){
			if(event.type == SDL_QUIT){
				window.done = 1;
			}
			if(event.type == SDL_KEYDOWN && event.key.repeat == 0){
				switch(event.key.keysym.sym){
					case SDLK_SPACE:
						setTexture(&sprite,"assets/world/block.png",&window.rnd);
						break;
					case SDLK_w:
						moveTexture(&sprite,(sprite.size.x += 10),(sprite.size.y));
						break;
					case SDLK_q:
						window.done = 1;
						break;
				}
			}
		}
		SDL_RenderClear(window.rnd);
		SDL_RenderCopy(window.rnd,background.image,NULL,&background.size);
		SDL_RenderCopy(window.rnd,sprite.image,NULL,&sprite.size);
		SDL_RenderPresent(window.rnd);
	}
    	SDL_DestroyRenderer(window.rnd);
    	SDL_DestroyWindow(window.window);
    	SDL_Quit();
    	return 0;
}
