#ifndef YAPE_MENU_H
#define YAPE_MENU_H
#include "../common.h"
#include "button.h"
//Generated with genfile -d menu.h -i "['../common.h']"

struct yape_menu{
	yape_button items[50];
	int count;
};

typedef struct yape_menu yape_menu;

yape_menu * yape_menu_add_button(yape_button * button, yape_menu * menu);

void yape_menu_update(yape_menu * menu, SDL_Renderer * rnd);

#endif //YAPE_MENU_H

