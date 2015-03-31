#include <graphics.h>
//Generated with genfile -c graphics.c -i "graphics.h"


void moveTexture(struct Texture * tex, int x, int y)
{
	(*tex).size.x = x;
	(*tex).size.y = y;
}

void setTexture(struct Texture * tex, char * tex_name, SDL_Renderer ** rnd){
	//int oldx = (*tex).size.x;
	//int oldy = (*tex).size.y;
	//*tex = createTexture(tex_name,oldx,oldy,rnd);
}
