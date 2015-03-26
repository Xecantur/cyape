#include "menu.h"



yape_menu * yape_menu_add_button(yape_button * button, yape_menu * menu){
	
	yape_menu * new_menu = malloc(1 * sizeof(menu));

	if(menu->count != 0){
		for(int i = 0; i <= menu->count; i++){
			new_menu->items[i] = menu->items[i];
			new_menu->count++;
		}
	} else {
		new_menu->items[0] = *button;
		new_menu->count++;
	}
	
	return new_menu;
}

void yape_menu_update(yape_menu * menu, SDL_Renderer * rnd){
	
	for(int i = 0; i <= menu->count; i++){
		yape_button_update(&menu->items[i],rnd);
	}
}
