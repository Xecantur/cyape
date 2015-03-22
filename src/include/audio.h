#ifndef AUDIO_H
#define AUDIO_H
#include "common.h"
//Generated with genfile -d audio.h -i "['common.h']"

#define Y_AUDIO_44KHZ 44100
#define Y_AUDIO_CHUNK_SIZE 4096
#define Y_AUDIO_FORMAT MIX_DEFAULT_FORMAT
#define Y_AUDIO_CHANNELS 2
#define Y_AUDIO_SUPPORTED MIX_INIT_OGG

struct y_audio_settings { 
	int freq;
	Uint16 format;
	int channels;
	int chunksize;
};


typedef struct y_audio_settings y_audio_settings;

struct y_audio { 
	Mix_Music * music;
	Mix_Chunk * sound_clip;
	char * filename;
	int channel;
};

typedef struct y_audio y_audio;

bool y_audio_init(y_audio_settings * settings);
bool y_load_music(char * music_file, y_audio * music);
void y_free_music(y_audio * music);
bool y_play_music(y_audio * result);
#define y_pause_music Mix_PauseMusic
#define y_resume_music Mix_ResumeMusic
bool y_load_sound(char * sound_file, y_audio * sound);
void y_free_sound(y_audio * sound);
bool y_play_sound(y_audio * sound);

#define y_audio_quit Mix_CloseAudio


#endif //AUDIO_H

