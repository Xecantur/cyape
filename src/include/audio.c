#include "audio.h"

yape_sound yape_load_sound(char * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system) {
	yape_sound s = {
		.channel = channel,
		.result = FMOD_System_CreateStream(system, sound, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &s.sound),
	};

	return s;
}

int yape_pause_sound(FMOD_CHANNEL ** channel) {
	FMOD_Channel_SetPaused(*channel, 1);
	return 1;
}

int yape_unpause_sound(FMOD_CHANNEL ** channel) {
	FMOD_Channel_SetPaused(*channel, 0);
	return 0;
}

void yape_play_sound(FMOD_SOUND * sound, FMOD_CHANNEL ** channel, FMOD_SYSTEM * system) {
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, channel);
}
