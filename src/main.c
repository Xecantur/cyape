#include "cyape.h"
//Generated with genfile -c main.c -i "cyape.h"


void hollaback_yall(y_texture * hresult, SDL_Renderer * hrnd){
	y_texture tmp = y_load_texture("assets/world/platform.png",hrnd);
	hresult = &tmp;
	hresult->loc.x = 300;
	hresult->loc.y = 200;
}



int main(){
	
	int hasChanged = 0, song_playing = 1;
	int music_paused = 0;
	char * a_list[3];
	
	a_list[0] = "assets/ui/background.png";
	a_list[1] = "assets/world/Alien.png";
	a_list[2] = "assets/world/block.png";
	
	y_texture texture_list[10];
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Couldn't Initialize SDL!\n");
		exit(-1);
    	}
	SDL_Event event;
    	y_window window = {
		.name = "Cyape 1.1",
		.done = 0,
		.loc = {
			.x = 0, .y = 0, .w = 800, .h = 600,
		},
	};
	window.window = SDL_CreateWindow(
		window.name,
		window.loc.x, window.loc.y,
		window.loc.w, window.loc.h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
	window.rnd = SDL_CreateRenderer(
		window.window,
		1, 
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	TTF_Init();
	TTF_Font * font = TTF_OpenFont("assets/fonts/main.ttf",20);
	//FMOD
	y_sound song;
	FMOD_SYSTEM * sound_system;
	song.channel = 0;
	FMOD_System_Create(&sound_system);
	FMOD_System_Init(sound_system, 1, FMOD_INIT_NORMAL, NULL);
	song = y_load_sound("assets/music/technicolor.mp3", song.channel, sound_system);
	//end FMOD

	//load_textures(a_list,2,&texture_list,window.rnd);
	texture_list[0] = y_load_texture(a_list[0],window.rnd);
	texture_list[1] = y_load_texture(a_list[1],window.rnd);
	texture_list[2] = y_load_texture(a_list[2],window.rnd);

	y_texture * background = &texture_list[0];
	y_texture * sprite = &texture_list[1];
		sprite->loc.x = 50;
		sprite->loc.y = 50;
	y_texture * block = &texture_list[2];
		block->loc.x = 50;
		block->loc.y = 50;
	y_texture sprite_back = *sprite;
	
	//SDL_Color color = {0,0,0,0};	

	y_menu main_menu[3];
	main_menu[0] = y_make_button(400,0,"Button 1 is a non-conformist","assets/ui/button.png",  font, window.rnd);
	main_menu[1] = y_make_button(400,100,"Button 2", "assets/ui/button.png", font, window.rnd);
	main_menu[2] = y_make_button(400,200,"Button 3", "assets/ui/button.png", font, window.rnd);
	//y_make_menu(main_menu, sizeof main_menu / sizeof main_menu[0], 50, 172);
	printf("Hello Button: ");  y_pprect(&main_menu[0].tex.loc);
	printf("Hello ButtonL: "); y_pprect(&main_menu[0].label.loc);
	
	y_texture result;

	int clicked = 0;

	//start with music paused;
    	while(window.done != 1){
		while(SDL_PollEvent(&event) != 0){
			if(event.type == SDL_QUIT){
				window.done = 1;
			}
			if(event.type == SDL_KEYDOWN ){
				switch(event.key.keysym.sym){
					case SDLK_SPACE:
						if(hasChanged == 0){
							sprite->img = block->img;
							hasChanged = 1;
							break;
						}
						if(hasChanged == 1){
							sprite->img = sprite_back.img;
							hasChanged = 0;
							break;
						}
						break;
					case SDLK_w:
						sprite->loc.y -= 20;
						break;
					case SDLK_s:
						sprite->loc.y += 20;
						break;
					case SDLK_a:
						sprite->loc.x -= 20;
						break;
					case SDLK_d:
						sprite->loc.x += 20;
						break;
					case SDLK_q:
						window.done = 1;
						break;
					case SDLK_p:
						if(music_paused == 0){
							music_paused = y_pause_sound(&song.channel);
							song_playing = 1;
							break;
						}
						if(music_paused == 1){
							music_paused = y_unpause_sound(&song.channel);
							song_playing = 0;
						}
						break;
				}
			}
			if(event.type == SDL_KEYUP ) {
				switch(event.key.keysym.sym) {
					case SDLK_w:
						sprite->loc.y += 20;
						break;
					case SDLK_s:
						sprite->loc.y -= 20;
						break;
					case SDLK_a:
						sprite->loc.x += 20;
						break;
					case SDLK_d:
						sprite->loc.x -= 20;
						break;
				}
			}
			if(event.type == SDL_MOUSEBUTTONDOWN){
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						clicked = if_clicked(event.motion.x,
							event.motion.y,
							main_menu[0], 
							&result, 
							window.rnd,
							&hollaback_yall);
				}
			}
		}
		if(song_playing == 0)
		{
			y_play_sound(song.sound,&song.channel, sound_system);
			song_playing = 1;
		}
			FMOD_System_Update(sound_system);
		SDL_RenderClear(window.rnd);
		SDL_RenderCopy(window.rnd,background->img,NULL,&background->loc);
		for(int i = 0; i <= 2; i++){
			SDL_RenderCopy(window.rnd, main_menu[i].tex.img, NULL, &main_menu[i].tex.loc);
		}
		for(int i = 0; i <= 2; i++){
			SDL_RenderCopy(window.rnd, main_menu[i].label.img, NULL, &main_menu[i].label.loc);
		}
		if(clicked == 1){
			SDL_RenderCopy(window.rnd,result.img, NULL, &result.loc);
		}
		SDL_RenderCopy(window.rnd,sprite->img,NULL,&sprite->loc);
		SDL_RenderPresent(window.rnd);
	}
	FMOD_Sound_Release(song.sound);
	FMOD_System_Close(sound_system);
	FMOD_System_Release(sound_system);
	TTF_CloseFont(font);
	TTF_Quit();
    	SDL_DestroyRenderer(window.rnd);
    	SDL_DestroyWindow(window.window);
    	SDL_Quit();
    	return 0;
}
