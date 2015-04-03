#include "audio.h"

yape_sound yape_load_sound(char * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system) {
	yape_sound s = {
		.channel = channel,
		.result = FMOD_System_CreateSound(system, sound, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &s.sound),
	};

	return s;
}

void yape_set_pause_sound(FMOD_CHANNEL * channel, int * paused) {
	FMOD_Channel_SetPaused(channel,!paused);
}

int yape_get_pause_sound(FMOD_CHANNEL * channel, int * paused) {
	FMOD_Channel_GetPaused(channel,paused);
	return *paused;
}

void yape_play_sound(FMOD_SOUND * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system) {
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, &channel);
}
