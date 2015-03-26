#ifndef YAPE_COMMON_H
#define YAPE_COMMON_H
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <lua.h>
#include <jansson.h>
#include <chipmunk/chipmunk.h>
//Generated with genfile -d common.h -i "['stdio.h', 'SDL2/SDL.h', 'SDL2/SDL_image.h', 'SDL2/SDL_ttf.h', 'fmodex/fmod.h']"

struct yape_pair {
	int x;
	int y;
};

typedef struct yape_pair yape_pair;


void yape_print_loc(SDL_Rect loc, char * name);
#endif //YAPE_COMMON_H
