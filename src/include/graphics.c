#include "graphics.h"
//Generated with genfile -c graphics.c -i "graphics.h"

void y_pprect(SDL_Rect * size){
	printf("Rect[x,y,w,h]: %d,%d | %d,%d\n",size->x,size->y,size->w,size->h);
}

void y_load_textures(char ** a_list, uint8_t n_textures, y_texture * t_list, SDL_Renderer * rnd) {
		
		
		for(uint8_t lt = 0; lt <= n_textures; lt++)
		{
			SDL_Surface * tmp = IMG_Load(a_list[lt]);
			t_list[lt].loc.h = tmp->h;
			t_list[lt].loc.w = tmp->w;
			t_list[lt].loc.x = 0;
			t_list[lt].loc.y = 0;
			t_list[lt].name = a_list[lt];
			t_list[lt].img = SDL_CreateTextureFromSurface(rnd, tmp);
			SDL_FreeSurface(tmp);
		}
}

y_texture y_load_texture(char * name, SDL_Renderer * rnd) {
		
		SDL_Surface * tmp = IMG_Load(name);
		y_texture t = {
			.loc.h = tmp->h,
			.loc.w = tmp->w,
			.loc.y = 0,
			.loc.x = 0,
			.name = name,
			.img = SDL_CreateTextureFromSurface(rnd,tmp)
		};
		SDL_FreeSurface(tmp);
		return t;
}

y_label y_make_label(char * text, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd) {
	y_label t_label;
	SDL_Surface * tmp = TTF_RenderUTF8_Solid(font, text, color);
	TTF_SizeText(font, text, &t_label.loc.w, &t_label.loc.h);
	t_label.color = color;
	t_label.text = text;
	t_label.loc.x = 0;
	t_label.loc.y = 0;
	t_label.font = font;
	t_label.img = SDL_CreateTextureFromSurface(rnd, tmp);
	SDL_FreeSurface(tmp); 
	return t_label;
}

y_button y_make_button(int x, int y, char * text, char * button_img, TTF_Font * font, SDL_Renderer * rnd){
	y_button t_button;
	t_button.tex = y_load_texture(button_img,rnd);
	SDL_Color default_color = { 0,0,0,0 };
	t_button.label = y_make_label(text, default_color, font, rnd);
	t_button.tex.loc.w = t_button.label.loc.w + 20;
	t_button.tex.loc.h = t_button.label.loc.h + 20;
	t_button.tex.loc.x = x;
	t_button.tex.loc.y = y;
	t_button.label.loc.x = x + 10; 
	t_button.label.loc.y = y + 10;
	return t_button;
}

void y_make_menu(y_menu * buttons, size_t length, int x, int padding){
	//This Function doesn't function right
	int i = 0;
	buttons[0].tex.loc.x = x;
	buttons[0].label.loc.x = (buttons[0].tex.loc.w - buttons[0].label.loc.w) / 2;
	buttons[0].label.loc.y = (buttons[0].tex.loc.h - buttons[0].label.loc.h) / 2;

	for(i = 1; i <= (int)length; i++){
		buttons[i].tex.loc.x = x;
		buttons[i].tex.loc.y = buttons[(i-1)].tex.loc.y + padding;
		buttons[i].label.loc.y = buttons[i].tex.loc.y + padding;
	}

}

int if_clicked(int mouse_x, int mouse_y, y_menu item,y_texture * result, SDL_Renderer *rnd, void (*hollaback)(y_texture * hresult, SDL_Renderer * hrnd)){
	SDL_Rect bounds = item.tex.loc;
	printf("Bounds: "); y_pprect(&bounds);
	printf("Mouse x,y: %d,%d\n",mouse_x,mouse_y);
	if( (mouse_x > bounds.x ) && (mouse_x < bounds.x + bounds.w ) && (mouse_y > bounds.y) && (mouse_y < bounds.y + bounds.h)){
			hollaback(result,rnd);
			return 1;
	}
	return 0;
}
