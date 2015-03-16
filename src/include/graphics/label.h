#ifndef LABEL_H
#define LABEL_H
#include "../common.h"
#include "texture.h"
//Generated with genfile -d label.h -i "['../common.h']"


struct y_label {
	y_img img;
	SDL_Color color;
	TTF_Font * font;
	char * label_txt;
	y_pair pos;
};

typedef struct y_label y_label;

y_label y_label_create(char * text, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd);

y_label y_label_create(char * text, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd){
	if(font == NULL){
		printf("Error couldn't find font/invalid pointer\n");
		exit(0);
	}
	y_label tmp_label;
	tmp_label.label_txt = text;
	tmp_label.img.asset_name = text;
	tmp_label.pos.x = 0;
	tmp_label.pos.y = 0;
	tmp_label.img.pos.x = 0;
	tmp_label.img.pos.y = 0;
	SDL_Surface * tmp = TTF_RenderUTF8_Solid(font,text,color);
	TTF_SizeText(font,text,&tmp_label.img.loc.w, &tmp_label.img.loc.h);
	tmp_label.color = color;
	tmp_label.font = font;
	tmp_label.img.loc.x = 0;
	tmp_label.img.loc.y = 0;
	tmp_label.img.data = SDL_CreateTextureFromSurface(rnd,tmp);
	SDL_FreeSurface(tmp);
	return tmp_label;
}

void y_label_update(y_label * label, SDL_Renderer * rnd);

void y_label_update(y_label * label, SDL_Renderer * rnd){
	label->img.pos.x = label->pos.x;
	label->img.pos.y = label->pos.y;
	y_img_update(&label->img,rnd);
}

#endif //LABEL_H
