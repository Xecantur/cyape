#ifndef MAIN_H
#define MAIN_H
#include "../include/yape.h"
//Generated with genfile -d main.h -i "['../include/common.h']"

void cb_test(void * data, SDL_Renderer * rnd);

void cb_test(void * data, SDL_Renderer * rnd){
	printf("Hello World!!! I'm a Callback!!!!!\n");
}

#endif //MAIN_H
