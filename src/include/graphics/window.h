#ifndef YAPE_WINDOW_H
#define YAPE_WINDOW_H
#include "../common.h"
//Generated with genfile -d window.h -i "['../common.h']"



struct yape_window{
	SDL_Window * window;
	SDL_Renderer * rnd;
	SDL_Rect loc;
	SDL_Event event;
	int done;
	char * title;
};

typedef struct yape_window yape_window;


#endif //WINDOW_H
