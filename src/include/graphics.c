#include "graphics.h"
//Generated with genfile -c graphics.c -i "graphics.h"

void y_pprect(SDL_Rect * size){
	printf("Rect[x,y,w,h]: %d,%d | %d,%d\n",size->x,size->y,size->w,size->h);
}

void y_load_textures(char ** a_list, uint8_t n_textures, y_texture * t_list, SDL_Renderer * rnd) {
		
		
		for(uint8_t lt = 0; lt <= n_textures; lt++)
		{
			SDL_Surface * tmp = IMG_Load(a_list[lt]);
			t_list[lt].loc.h = tmp->h;
			t_list[lt].loc.w = tmp->w;
			t_list[lt].loc.x = 0;
			t_list[lt].loc.y = 0;
			t_list[lt].name = a_list[lt];
			t_list[lt].image = SDL_CreateTextureFromSurface(rnd, tmp);
			SDL_FreeSurface(tmp);
		}
}

y_texture y_load_texture(char * name, SDL_Renderer * rnd) {
		
		SDL_Surface * tmp = IMG_Load(name);
		y_texture t = {
			.loc.h = tmp->h,
			.loc.w = tmp->w,
			.loc.y = 0,
			.loc.x = 0,
			.name = name,
			.image = SDL_CreateTextureFromSurface(rnd,tmp)
		};
		SDL_FreeSurface(tmp);
		return t;
}

y_label y_make_label(char * text, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd) {
	y_label t_label;
	SDL_Surface * tmp = TTF_RenderUTF8_Solid(font, text, color);
	TTF_SizeText(font, text, &t_label.loc.w, &t_label.loc.h);
	t_label.color = color;
	t_label.text = text;
	t_label.loc.x = 0;
	t_label.loc.y = 0;
	t_label.font = font;
	t_label.image = SDL_CreateTextureFromSurface(rnd, tmp);
	SDL_FreeSurface(tmp); 
	return t_label;
}

y_button y_make_button(char * text, char * button_img, TTF_Font * font, SDL_Renderer * rnd){
	y_button t_button;
	t_button.img = y_load_texture(button_img,rnd);
	SDL_Color default_color = { 0,0,0,0 };
	t_button.label = y_make_label(text, default_color, font, rnd);
	return t_button;
}
