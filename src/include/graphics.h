#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include "common.h"
//Generated with genfile -d graphics.h -i "['common.h']"

void pprect(SDL_Rect * rect); //print pointer rect

/*------------------Window-----------------------------*/

struct Window{
	SDL_Window * window;
	char * title;
	int done;
	SDL_Renderer * rnd;
	SDL_Rect size;
};


/*------------------------Texture-----------------------------*/

struct Texture{
	SDL_Rect size;
	SDL_Texture * image;
	char * tex_name;
	SDL_Renderer * rnd;
};


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
