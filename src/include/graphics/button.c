#include "button.h"

yape_button yape_make_button(char * button_txt, yape_img * img, TTF_Font * font, SDL_Color font_color, SDL_Renderer * rnd){

	yape_button tmp;
	tmp.label = yape_label_create(button_txt, font_color, font, rnd);
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

void yape_button_update(yape_button * button, SDL_Renderer * rnd){
	//here comes the tricky part figuring out automatic placement
	button->button_img->pos.x = button->pos.x;
	button->button_img->pos.y = button->pos.y;
	button->label.pos.x = button->pos.x + 10;
	button->label.pos.y = button->pos.y + 5;
	yape_img_update(button->button_img, rnd);
	yape_label_update(&button->label, rnd);
}

void yape_button_onClick(const SDL_Rect * bounds, int mouse_x, int mouse_y, void * data, SDL_Renderer * rnd, void (* callback)(void * data, SDL_Renderer * rnd)){
	if( mouse_x > bounds->x && mouse_x < (bounds->x + bounds->w)){
		if( mouse_y > bounds->y && mouse_y < (bounds->y + bounds->h)){
			callback(data,rnd);
		}
	}
}

bool yape_button_was_clicked(const SDL_Rect * bounds, int mouse_x, int mouse_y){
	if(mouse_x > bounds->x && mouse_x < (bounds->x + bounds->w)){
		if( mouse_y > bounds->y && mouse_y < (bounds->y + bounds->h)){
			return true;
		}
	}
	return false;
}
