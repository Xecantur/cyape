#include "texture.h"
//Generated with genfile -d texture.h -i "['../common.h']"
yape_img yape_img_load(char * name, SDL_Renderer * rnd){
	
	SDL_Surface * tmp = IMG_Load(name);
	yape_img t = {
		.loc.h = tmp->h,
		.loc.w = tmp->w,
		.loc.x = 0,
		.loc.y = 0,
		.pos.x = 0,
		.pos.y = 0,
		.asset_name = name,
		.data = SDL_CreateTextureFromSurface(rnd,tmp)
	};
	SDL_FreeSurface(tmp);
	return t;
}

void yape_batch_img_load(char ** asset_list, int num, yape_img * img_list, SDL_Renderer * rnd){
	for(int i = 0; i <= num; i++){
		SDL_Surface * tmp = IMG_Load(asset_list[i]);
		img_list[i].loc.h = tmp->h;
		img_list[i].loc.w = tmp->w;
		img_list[i].loc.x = 0;
		img_list[i].loc.y = 0;
		img_list[i].pos.x = 0;
		img_list[i].pos.y = 0;
		img_list[i].data = SDL_CreateTextureFromSurface(rnd,tmp);
		SDL_FreeSurface(tmp);
	}
}

void yape_img_update(yape_img * img,SDL_Renderer *rnd){
	img->loc.x = img->pos.x;
	img->loc.y = img->pos.y;
	SDL_RenderCopy(rnd, img->data, NULL, &img->loc);
}

