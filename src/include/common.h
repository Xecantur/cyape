#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <fmodex/fmod.h>
#include <chipmunk/chipmunk.h>
//Generated with genfile -d common.h -i "['stdio.h', 'SDL2/SDL.h', 'SDL2/SDL_image.h', 'SDL2/SDL_ttf.h', 'fmodex/fmod.h']"

struct y_pair {
	int x;
	int y;
};

typedef struct y_pair y_pair;

#endif //COMMON_H
