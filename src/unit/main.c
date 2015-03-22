#include "main.h"
int main(){


	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS ) != 0){
		printf("Couldn't initialize SDL\n");
		exit(-1);
	}


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
	y_img button_img = y_img_load("assets/ui/button.png",my_window.rnd);
	y_label text = y_label_create("stuff",color,font,my_window.rnd);

	y_button button = y_make_button("First Button lolz", &button_img, font, color, my_window.rnd);

	y_audio_settings audio_settings = {
		.freq = Y_AUDIO_44KHZ,
		.format = Y_AUDIO_FORMAT,
		.channels = Y_AUDIO_CHANNELS,
		.chunksize = Y_AUDIO_CHUNK_SIZE
	};
	y_audio_init(&audio_settings);
	y_audio music;
	bool loaded = y_load_music("assets/music/mists_of_time_4T.ogg",&music);
	if(loaded == false) exit(-3);
	loaded = y_play_music(&music);
	if(loaded == false) exit(-3);
	button.pos.x = 400;
	button.pos.y = 300;
	while(!my_window.done){
		while(SDL_PollEvent(&my_window.event) != 0){
			if(my_window.event.type == SDL_QUIT){
				my_window.done = 1;
			}
			if(my_window.event.type == SDL_KEYDOWN && my_window.event.key.repeat == 0){
				switch(my_window.event.key.keysym.sym){
					case SDLK_q:
						my_window.done = 1;
						break;
				}
			}
			if(my_window.event.type == SDL_MOUSEBUTTONDOWN){
				switch(my_window.event.button.button){
					case SDL_BUTTON_LEFT:
						onClick(&button.button_img->loc, my_window.event.motion.x, my_window.event.motion.y, NULL, my_window.rnd, &cb_test);
						break;
				}
			}
		}
		SDL_RenderClear(my_window.rnd);
		y_img_update(&test,my_window.rnd);
		y_label_update(&text,my_window.rnd);
		y_button_update(&button,my_window.rnd);
		SDL_RenderPresent(my_window.rnd);
	}

	TTF_CloseFont(font);
	TTF_Quit();
	y_free_music(&music);
	y_audio_quit();
	SDL_DestroyTexture(button.button_img->data);
	SDL_DestroyTexture(button.label.r_txt);
	SDL_DestroyTexture(test.data);
	SDL_DestroyTexture(text.r_txt);
	SDL_DestroyRenderer(my_window.rnd);
	SDL_DestroyWindow(my_window.window);
	SDL_Quit();

	return 0;
}
