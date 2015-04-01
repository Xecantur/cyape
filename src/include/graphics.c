#include "graphics.h"
//Generated with genfile -c graphics.c -i "graphics.h"

void pprect(SDL_Rect * size){
	printf("Rect[x,y,w,h]: %d,%d | %d,%d\n",size->x,size->y,size->w,size->h);
}
