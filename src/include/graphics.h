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

typedef struct Window Window; 

int mainLoop(SDL_Event event, void * data);

Window createWindow(char * title, int x, int y, int w, int h);


/*------------------------Texture-----------------------------*/

struct Texture{
	SDL_Rect size;
	SDL_Texture * image;
	char tex_name[40];
	SDL_Renderer * rnd;
};

typedef struct Texture Texture;

Texture * createTexture(char * tex_name, int x, int y, SDL_Renderer * rnd);
void setTexture(Texture * tex, char * tex_name, SDL_Renderer * rnd);
void moveTexture(Texture * tex, int x, int y);
/*-----------------------Text-------------------------------*/

struct Text{
	char txt[80];
	int font_size;
	SDL_Color color;
	SDL_Texture * rtxt;
	TTF_Font * font;
	SDL_Rect size;
};

typedef struct Text Text;

void setText(Text * txt, char text[80],int font_size,SDL_Renderer * rnd);
void moveText(Text * txt, int x, int y, SDL_Renderer * rnd);
/*------------------------Menu----------------------------*/

#endif //__GRAPHICS_H__
