#include "main.h"
int main(){
	y_window my_window = {
		.title = "Cyape FINAL RW v1.5",
		.done = 0,
		.loc = { .x = 0, .y = 0, .w = 800, .h = 600 ,},
	};
	my_window.window = SDL_CreateWindow(my_window.title, 0,0,800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	my_window.rnd = SDL_CreateRenderer(my_window.window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	TTF_Init();

	TTF_Font * font = TTF_OpenFont("assets/fonts/main.ttf", 20);
	SDL_Color color = { .r = 255, .b = 255, .g = 255, .a = 0 };
	y_img test = y_img_load("assets/world/block.png",my_window.rnd);
	y_label text = y_label_create("stuff",color,font,my_window.rnd);

	while(!my_window.done){
		while(SDL_PollEvent(&my_window.event) != 0){
			if(my_window.event.type == SDL_QUIT){
				my_window.done = 1;
			}
		}
		SDL_RenderClear(my_window.rnd);
		y_img_update(&test,my_window.rnd);
		y_label_update(&text,my_window.rnd);
		SDL_RenderPresent(my_window.rnd);
	}

	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyTexture(test.data);
	SDL_DestroyTexture(text.img.data);
	SDL_DestroyRenderer(my_window.rnd);
	SDL_DestroyWindow(my_window.window);
	SDL_Quit();

	return 0;
}
