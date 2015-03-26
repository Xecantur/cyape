#include "main.h"
int main(){


	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS ) != 0){
		printf("Couldn't initialize SDL\n");
		exit(-1);
	}


	yape_window my_window = {
		.title = "Cyape FINAL RW v1.5",
		.done = 0,
		.loc = { .x = 0, .y = 0, .w = 800, .h = 600 ,},
	};
	my_window.window = SDL_CreateWindow(my_window.title, 0,0,800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	my_window.rnd = SDL_CreateRenderer(my_window.window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	TTF_Init();

	TTF_Font * font = TTF_OpenFont("assets/fonts/main.ttf", 20);
	SDL_Color color = { .r = 255, .b = 255, .g = 255, .a = 0 };
	yape_img bg = yape_img_load("assets/ui/background.png",my_window.rnd);
	yape_img logo = yape_img_load("assets/ui/logo.png",my_window.rnd);
	logo.pos.x = 400;
	logo.pos.y = 0;
	
	yape_img button_img = yape_img_load("assets/ui/button.png",my_window.rnd);
	yape_img b_select_img = button_img;
	yape_img b_music_img  = button_img;
	yape_img b_quit_img   = button_img; 

	yape_label text = yape_label_create("v1.5.0",color,font,my_window.rnd);

	yape_button b_select = yape_make_button("Level Select", &b_select_img, font, color, my_window.rnd);
	yape_button b_music = yape_make_button("Pause Music", &b_music_img, font, color, my_window.rnd);
	yape_button b_quit = yape_make_button("Quit", &b_quit_img, font, color, my_window.rnd);
	b_music.button_img->loc.w = b_select.button_img->loc.w;
	b_music.button_img->loc.h = b_select.button_img->loc.h;
	b_quit.button_img->loc.w = b_select.button_img->loc.w;

	b_select.pos.x = 400;
	b_select.pos.y = 200;
	b_music.pos.x = b_select.pos.x;
	b_music.pos.y = b_select.pos.y + b_select.button_img->loc.h;
	b_quit.pos.x = b_select.pos.x;
	b_quit.pos.y = b_music.pos.y + b_music.button_img->loc.h;

	yape_menu main_menu;
	main_menu.count = 0;
	main_menu.items[0] = b_select;
	main_menu.items[1] = b_music;
	main_menu.items[2] = b_quit;
	main_menu.count = 2;

	yape_audio_settings audio_settings = {
		.freq = YAPE_AUDIO_44KHZ,
		.format = YAPE_AUDIO_FORMAT,
		.channels = YAPE_AUDIO_CHANNELS,
		.chunksize = YAPE_AUDIO_CHUNK_SIZE
	};
	yape_audio_init(&audio_settings);
	yape_audio music;
	bool loaded = yape_load_music("assets/music/mists_of_time_4T.ogg",&music);
	if(loaded == false) exit(-3);
	loaded = yape_play_music(&music);
	if(loaded == false) exit(-3);
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
						if(yape_button_was_clicked(&b_select.button_img->loc, my_window.event.motion.x, my_window.event.motion.y)){
							start_game_screen(&bg,&my_window,color,font,my_window.rnd);
						}
						yape_button_onClick(&b_music.button_img->loc, my_window.event.motion.x, my_window.event.motion.y, NULL, my_window.rnd, &cb_pause_music);
						if(yape_button_was_clicked(&b_quit.button_img->loc, my_window.event.motion.x, my_window.event.motion.y)){
								my_window.done = 1;
						}
						break;
				}
			}
		}
		SDL_RenderClear(my_window.rnd);
		yape_img_update(&bg,my_window.rnd);
		yape_img_update(&logo,my_window.rnd);
		yape_label_update(&text,my_window.rnd);
		yape_menu_update(&main_menu,my_window.rnd);
		SDL_RenderPresent(my_window.rnd);
	}

	TTF_CloseFont(font);
	TTF_Quit();
	yape_free_music(&music);
	yape_audio_quit();
	SDL_DestroyTexture(b_select.button_img->data);
	SDL_DestroyTexture(b_select.label.r_txt);
	SDL_DestroyTexture(b_music.button_img->data);
	SDL_DestroyTexture(b_music.label.r_txt);
	SDL_DestroyTexture(b_quit.button_img->data);
	SDL_DestroyTexture(b_quit.label.r_txt);
	SDL_DestroyTexture(bg.data);
	SDL_DestroyTexture(text.r_txt);
	SDL_DestroyRenderer(my_window.rnd);
	SDL_DestroyWindow(my_window.window);
	SDL_Quit();

	return 0;
}
