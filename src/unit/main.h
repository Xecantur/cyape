#ifndef MAIN_H
#define MAIN_H
#include "../include/yape.h"
//Generated with genfile -d main.h -i "['../include/common.h']"

void cb_test(void * data, SDL_Renderer * rnd);

void cb_test(void * data, SDL_Renderer * rnd){
	printf("Hello World!!! I'm a Callback!!!!!\n");
}

void cb_pause_music(void * data, SDL_Renderer * rnd);

static bool paused = false;
void cb_pause_music(void * data, SDL_Renderer * rnd){
	if(paused == false){
		yape_pause_music();
		paused = true;
	}
	else if(paused == true) {
		yape_resume_music();
		paused = false;
	}
}
void cb_back(void * data, SDL_Renderer * rnd);

void cb_back(void * data, SDL_Renderer * rnd){
	//y_window * w = ((y_window * ) data);
	//w->done = 1;
	bool * t = ((bool *) data);
	*t = true;
}


void level_one(void);

void level_one(void){
 	printf("Stuff\n");
}


void start_game_screen(yape_img * bg, yape_window * window, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd);


void start_game_screen(yape_img * bg, yape_window * window, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd){
	
	bool done = false;
	
	yape_label screen = yape_label_create("Level Select", color, font, rnd);
	screen.pos.x = 400;
	screen.pos.y = 10;
	yape_img button_img = yape_img_load("assets/ui/button.png",rnd);
	yape_button b_back = yape_make_button("Back",&button_img,font,color,rnd);
	b_back.pos.x = 400;
	b_back.pos.y = 100;

	while(!done){
		while(SDL_PollEvent(&window->event) != 0){

			if(window->event.type == SDL_QUIT){
				window->done = 1;
				done = true;
			}
			if(window->event.type == SDL_KEYDOWN && window->event.key.repeat == 0){
				switch(window->event.key.keysym.sym){
					case SDLK_q:
						window->done = 1;
						break;
				}
			}
			if(window->event.type == SDL_MOUSEBUTTONDOWN){
				switch(window->event.button.button){
					case SDL_BUTTON_LEFT:
						yape_button_onClick(&b_back.button_img->loc, window->event.motion.x, window->event.motion.y, &done, NULL, &cb_back);
						break;
				}
			}

		}
		SDL_RenderClear(rnd);
		yape_img_update(bg, rnd);
		yape_label_update(&screen, rnd);
		yape_button_update(&b_back, rnd);
		SDL_RenderPresent(rnd);
	}

	SDL_DestroyTexture(screen.r_txt);
}

#endif //MAIN_H
