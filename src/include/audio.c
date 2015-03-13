#include "audio.h"

y_sound y_load_sound(char * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system) {
	y_sound s = {
		.channel = channel,
		.result = FMOD_System_CreateStream(system, sound, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &s.sound),
	};

	return s;
}

int y_pause_sound(FMOD_CHANNEL ** channel) {
	FMOD_Channel_SetPaused(*channel, 1);
	return 1;
}

int y_unpause_sound(FMOD_CHANNEL ** channel) {
	FMOD_Channel_SetPaused(*channel, 0);
	return 0;
}

void y_play_sound(FMOD_SOUND * sound, FMOD_CHANNEL ** channel, FMOD_SYSTEM * system) {
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, channel);
}
