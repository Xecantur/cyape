#ifndef __AUDIO_H__
#define __AUDIO_H__
//Generated with genfile -d audio.h
#include "common.h"

//! \file
//!  Audio module Definitions;
//! \brief Data Type for loading and playing audio
//!
//! yape_sound and the accompanying functions handles loading and playing sound.
//!
//! you will still need to initialize FMOD_SYSTEM and free FMOD_SYSTEM and sound
//! manually via FMOD_System_Init, FMOD_System_Create, FMOD_Sound_Release,
//! FMOD_System_Close, FMOD_System_Release family of functions.
//! 
//! Eventually I may do this via a sound_init() sound_quit()
struct yape_sound {
	FMOD_SOUND  * sound;
	FMOD_CHANNEL * channel;
	FMOD_RESULT    result;
};

typedef struct yape_sound yape_sound;

yape_sound yape_load_sound(char * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system);
//! \fn yape_load_sound(char * sound, FMOD_CHANNEL * channel, FMOD_SYSTEM * system)
//! \param sound C string path to sound file
//! \param channel channel in which sound plays
//! \param system on which sound plays

int yape_pause_sound(FMOD_CHANNEL ** channel); 
//! \fn yape_pause_sound(FMOD_CHANNEL ** channel)
//! \param channel channel to pause

int yape_unpause_sound(FMOD_CHANNEL ** channel);
//! \fn yape_unpause_sound(FMOD_CHANNEL ** channel);
//! \param channel channel to unpause

void yape_play_sound(FMOD_SOUND * sound, FMOD_CHANNEL ** channel, FMOD_SYSTEM * system); 
//! \fn yape_play_sound(FMOD_SOUND * sound, FMOD_CHANNEL ** channel, FMOD_SYSTEM * system)
//! \param sound sound that you want to play
//! \param channel in which to play sound
//! \param system on which to play sound
#endif //__AUDIO_H__
