#ifndef YAPE_BUTTON_H
#define YAPE_BUTTON_H
#include "../common.h"
#include "texture.h"
#include "label.h"
//Generated with genfile -d button.h -i "['../common.h']"


struct yape_button {
	yape_img   * button_img;
	yape_label   label;
	yape_pair pos;
	char * button_text;
};

typedef struct yape_button yape_button;

yape_button yape_make_button(char * button_txt, yape_img * img, TTF_Font * font, SDL_Color font_color, SDL_Renderer * rnd);

void yape_button_update(yape_button * button, SDL_Renderer * rnd);

void yape_button_onClick(const SDL_Rect * bounds, int mouse_x, int mouse_y, void * data, SDL_Renderer * rnd, void (* callback)(void * data, SDL_Renderer * rnd));

bool yape_button_was_clicked(const SDL_Rect * bounds, int mouse_x, int mouse_y);

#endif //YAPE_BUTTON_H

