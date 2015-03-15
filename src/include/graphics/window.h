#ifndef WINDOW_H
#define WINDOW_H
#include "../common.h"
//Generated with genfile -d window.h -i "['../common.h']"



struct y_window{
	SDL_Window * window;
	SDL_Renderer * rnd;
	SDL_Rect loc;
	char * title;
};

typedef struct y_window y_window;


#endif //WINDOW_H
