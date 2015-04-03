#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include "common.h"
//Generated with genfile -d graphics.h -i "['common.h']"

void yape_pprect(SDL_Rect * rect); //print pointer rect

/*------------------Window-----------------------------*/

struct yape_window{
	SDL_Window * window;
	char * name;
	int done;
	SDL_Renderer * rnd;
	SDL_Rect size;
};

typedef struct yape_window yape_window;

/*------------------------Texture-----------------------------*/

struct yape_texture{
	SDL_Rect size;
	SDL_Texture * image;
	char * name;
	SDL_Renderer * rnd;
};

typedef struct yape_texture yape_texture;

void yape_load_textures(char ** a_list, uint8_t n_textures, yape_texture * t_list, SDL_Renderer * rnd);
yape_texture yape_load_texture(char * name, SDL_Renderer * rnd);
/*-----------------------Text-------------------------------*/

struct yape_label{
	char * text;
	int font_size;
	SDL_Color color;
	SDL_Texture * image;
	TTF_Font * font;
	SDL_Rect size;
};

typedef struct yape_label yape_label;
yape_label yape_make_label(char * text, TTF_Font * font, int w, int h, SDL_Color color, SDL_Renderer * rnd);
/*------------------------Menu----------------------------*/

#endif //__GRAPHICS_H__
