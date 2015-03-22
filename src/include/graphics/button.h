#ifndef BUTTON_H
#define BUTTON_H
#include "../common.h"
#include "texture.h"
#include "label.h"
//Generated with genfile -d button.h -i "['../common.h']"


struct y_button {
	y_img   * button_img;
	y_label   label;
	y_pair pos;
	char * button_text;
};

typedef struct y_button y_button;

y_button y_make_button(char * button_txt, y_img * img, TTF_Font * font, SDL_Color font_color, SDL_Renderer * rnd);


y_button y_make_button(char * button_txt, y_img * img, TTF_Font * font, SDL_Color font_color, SDL_Renderer * rnd){

	y_button tmp;
	tmp.label = y_label_create(button_txt, font_color, font, rnd);
	tmp.label.pos.x = 10;
	tmp.label.pos.y = 5;
	tmp.button_img = img;
	tmp.button_img->loc.w = tmp.label.loc.w + 20;
	tmp.button_img->loc.h = tmp.label.loc.h + 10;
	tmp.pos.x = 0;
	tmp.pos.y = 0;
	tmp.button_text = button_txt;
	return tmp;
}
void y_button_update(y_button * button, SDL_Renderer * rnd);

void y_button_update(y_button * button, SDL_Renderer * rnd){
	//here comes the tricky part figuring out automatic placement
	button->button_img->pos.x = button->pos.x;
	button->button_img->pos.y = button->pos.y;
	button->label.pos.x = button->pos.x + 10;
	button->label.pos.y = button->pos.y + 5;
	y_img_update(button->button_img, rnd);
	y_label_update(&button->label, rnd);
}

void onClick(const SDL_Rect * bounds, int mouse_x, int mouse_y, void * data, SDL_Renderer * rnd, void (* callback)(void * data, SDL_Renderer * rnd));

void onClick(const SDL_Rect * bounds, int mouse_x, int mouse_y, void * data, SDL_Renderer * rnd, void (* callback)(void * data, SDL_Renderer * rnd)){
	if( mouse_x > bounds->x && mouse_x < (bounds->x + bounds->w)){
		if( mouse_y > bounds->y && mouse_y < (bounds->y + bounds->h)){
			callback(data,rnd);
		}
	}
}

#endif //BUTTON_H

