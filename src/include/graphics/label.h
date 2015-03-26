#ifndef YAPE_LABEL_H
#define YAPE_LABEL_H
#include "../common.h"
#include "texture.h"
//Generated with genfile -d label.h -i "['../common.h']"


struct yape_label {
	SDL_Texture * r_txt;
	SDL_Rect loc;
	SDL_Color color;
	TTF_Font * font;
	char * text;
	yape_pair pos;
};

typedef struct yape_label yape_label;

yape_label yape_label_create(char * text, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd);

void yape_label_update(yape_label * label, SDL_Renderer * rnd);

#endif //YAPE_LABEL_H
