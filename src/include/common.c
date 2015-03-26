#include "common.h"

void yape_print_loc(SDL_Rect loc, char * name){
	printf("%s Loc: %d x %d at %d,%d\n",name,loc.w,loc.h,loc.x,loc.y);
}
