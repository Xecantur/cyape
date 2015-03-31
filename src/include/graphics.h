#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include <common.h>
//Generated with genfile -d graphics.h -i "['common.h']"

void prect(SDL_Rect rect); //print rect
void pprect(SDL_Rect * rect); //print pointer rect

/*------------------Window-----------------------------*/

struct Window{
	SDL_Window * window;
	char * title;
	int done;
	SDL_Renderer * rnd;
	struct size {
		int x; int y;
		int w; int h;
	}size;
};


int mainLoop(SDL_Event event, void * data);



/*------------------------Texture-----------------------------*/

struct Texture{
	SDL_Rect size;
	SDL_Texture * image;
	char tex_name[40];
	SDL_Renderer * rnd;
};


void set_texture(struct Texture * tex, char * tex_name, SDL_Renderer ** rnd);
void move_texture(struct Texture * tex, int x, int y);
/*-----------------------Text-------------------------------*/

struct Text{
	char txt[80];
	int font_size;
	SDL_Color color;
	SDL_Texture * rtxt;
	TTF_Font * font;
	SDL_Rect size;
};


void set_text(struct Text * txt, char text[80],int font_size,SDL_Renderer * rnd);
void move_text(struct Text * txt, int x, int y, SDL_Renderer * rnd);
/*------------------------Menu----------------------------*/

#endif //__GRAPHICS_H__
