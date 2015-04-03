#include "graphics.h"
//Generated with genfile -c graphics.c -i "graphics.h"

void yape_pprect(SDL_Rect * size){
	printf("Rect[x,y,w,h]: %d,%d | %d,%d\n",size->x,size->y,size->w,size->h);
}

void yape_load_textures(char ** a_list, uint8_t n_textures, yape_texture * t_list, SDL_Renderer * rnd) {
		
		
		for(uint8_t lt = 0; lt <= n_textures; lt++)
		{
			SDL_Surface * tmp = IMG_Load(a_list[lt]);
			t_list[lt].size.h = tmp->h;
			t_list[lt].size.w = tmp->w;
			t_list[lt].size.x = 0;
			t_list[lt].size.y = 0;
			t_list[lt].name = a_list[lt];
			t_list[lt].image = SDL_CreateTextureFromSurface(rnd, tmp);
			SDL_FreeSurface(tmp);
		}
}

yape_texture yape_load_texture(char * name, SDL_Renderer * rnd) {
		
		SDL_Surface * tmp = IMG_Load(name);
		yape_texture t = {
			.size.h = tmp->h,
			.size.w = tmp->w,
			.size.y = 0,
			.size.x = 0,
			.name = name,
			.image = SDL_CreateTextureFromSurface(rnd,tmp)
		};
		SDL_FreeSurface(tmp);
		return t;
}

yape_label yape_make_label(char * text,TTF_Font * font, int w, int h, SDL_Color color, SDL_Renderer * rnd) {
	yape_label t_label;
	SDL_Surface * tmp = TTF_RenderUTF8_Solid(font, text, color);
	TTF_SizeText(font, text, &w, &h);
	t_label.color = color;
	t_label.text = text;
	t_label.size.w = w;
	t_label.size.h = h;
	t_label.size.x = 0;
	t_label.size.y = 0;
	t_label.font = font;
	t_label.image = SDL_CreateTextureFromSurface(rnd, tmp);
	SDL_FreeSurface(tmp); 
	return t_label;
}
