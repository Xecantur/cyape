#include <graphics.h>
//Generated with genfile -c graphics.c -i "graphics.h"

Window createWindow(char * title, int x, int y, int w, int h){
	Window window;
	window.window = SDL_CreateWindow(title,x,y,w,h, SDL_WINDOW_SHOWN);
	window.size.x = x;
	window.size.y = y;
	window.size.w = w;
	window.size.h = h;
	window.title = title;
	window.done = 0;
	return window;
}

Texture * createTexture(char * tex_name, int x, int y, SDL_Renderer * rnd){
	SDL_Surface * tmp = IMG_Load(tex_name);
	if(tmp == NULL){
		printf("Unable to load image \"%s\"!\n",tex_name);
		SDL_FreeSurface(tmp);
		exit(-2);
	}
	Texture tex;
	tex.image = SDL_CreateTextureFromSurface(rnd,tmp);
	tex.size.w = tmp->w;
	tex.size.h = tmp->w;
	tex.size.x = x;
	tex.size.y = y;
	SDL_FreeSurface(tmp);
	Texture * t = &tex;
	return t;
}

void moveTexture(Texture * tex, int x, int y)
{
	tex->size.x = x;
	tex->size.y = y;
}

void setTexture(Texture * tex, char * tex_name, SDL_Renderer * rnd){
	int oldx = tex->size.x;
	int oldy = tex->size.y;
	tex = createTexture(tex_name,oldx,oldy,rnd);
}
