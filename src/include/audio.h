#ifndef __AUDIO_H__
#define __AUDIO_H__
//Generated with genfile -d audio.h
#include "common.h"

struct yape_sound {
	FMOD_SOUND  * sound;
	FMOD_CHANNEL * channel;
	FMOD_RESULT    result;
};

typedef struct yape_sound yape_sound;

yape_sound yape_load_sound(char * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system);
void yape_pause_sound(FMOD_CHANNEL * channel);
void yape_set_pause_sound(FMOD_CHANNEL * channel, int * paused);
int  yape_get_pause_sound(FMOD_CHANNEL * channel, int * paused);
void yape_play_sound(FMOD_SOUND * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system);
#endif //__AUDIO_H__
