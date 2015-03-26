#ifndef YAPE_TEXTURE_H
#define YAPE_TEXTURE_H
#include "../common.h"
//Generated with genfile -d texture.h -i "['../common.h']"


struct yape_img{
	
	SDL_Texture * data;
	SDL_Rect loc;
	char * asset_name;
	yape_pair pos;
};

typedef struct yape_img yape_img;

yape_img yape_img_load(char * name, SDL_Renderer * rnd);


void yape_batch_img_load(char ** asset_list, int num, yape_img * img_list, SDL_Renderer * rnd);

void yape_img_update(yape_img * img,SDL_Renderer *rnd);

#endif //YAPE_TEXTURE_H
