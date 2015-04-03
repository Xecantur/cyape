#include "graphics.h"
//Generated with genfile -c graphics.c -i "graphics.h"

void pprect(SDL_Rect * size){
	printf("Rect[x,y,w,h]: %d,%d | %d,%d\n",size->x,size->y,size->w,size->h);
}

void load_textures(char ** a_list, uint8_t n_textures, Texture * t_list, SDL_Renderer * rnd) {
		
		
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
