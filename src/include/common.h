#ifndef COMMON_H
#define COMMON_H
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <jansson.h>
#include <chipmunk/chipmunk.h>
//Generated with genfile -d common.h -i "['stdio.h', 'SDL2/SDL.h', 'SDL2/SDL_image.h', 'SDL2/SDL_ttf.h', 'fmodex/fmod.h']"

struct y_pair {
	int x;
	int y;
};

typedef struct y_pair y_pair;


void y_print_loc(SDL_Rect loc, char * name);
//	printf("%s Loc: %d x %d at %d,%d\n", name, loc.w, loc.h, loc.x, loc.y);
//}
#endif //COMMON_H
