#include "common.h"

void y_print_loc(SDL_Rect loc, char * name){
	printf("%s Loc: %d x %d at %d,%d\n",name,loc.w,loc.h,loc.x,loc.y);
}
