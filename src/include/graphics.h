#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include "common.h"
//Generated with genfile -d graphics.h -i "['common.h']"

void pprect(SDL_Rect * rect); //print pointer rect

/*------------------Window-----------------------------*/

struct Window{
	SDL_Window * window;
	char * name;
	int done;
	SDL_Renderer * rnd;
	SDL_Rect size;
};

typedef struct Window Window;

/*------------------------Texture-----------------------------*/

struct Texture{
	SDL_Rect size;
	SDL_Texture * image;
	char * name;
	SDL_Renderer * rnd;
};

typedef struct Texture Texture;
void load_textures(char ** a_list, uint8_t n_textures,Texture * t_list,SDL_Renderer * rnd);
/*-----------------------Text-------------------------------*/

struct Text{
	char txt[80];
	int font_size;
	SDL_Color color;
	SDL_Texture * rtxt;
	TTF_Font * font;
	SDL_Rect size;
};

/*------------------------Menu----------------------------*/

#endif //__GRAPHICS_H__
