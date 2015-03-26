#ifndef YAPE_AUDIO_H
#define YAPE_AUDIO_H
#include "common.h"
//Generated with genfile -d audio.h -i "['common.h']"

#define YAPE_AUDIO_44KHZ 44100
#define YAPE_AUDIO_CHUNK_SIZE 4096
#define YAPE_AUDIO_FORMAT MIX_DEFAULT_FORMAT
#define YAPE_AUDIO_CHANNELS 2
#define YAPE_AUDIO_SUPPORTED MIX_INIT_OGG

struct yape_audio_settings { 
	int freq;
	Uint16 format;
	int channels;
	int chunksize;
};


typedef struct yape_audio_settings yape_audio_settings;

struct yape_audio { 
	Mix_Music * music;
	Mix_Chunk * sound_clip;
	char * filename;
	int channel;
};

typedef struct yape_audio yape_audio;

bool yape_audio_init(yape_audio_settings * settings);
bool yape_load_music(char * music_file, yape_audio * music);
void yape_free_music(yape_audio * music);
bool yape_play_music(yape_audio * result);
#define yape_pause_music Mix_PauseMusic
#define yape_resume_music Mix_ResumeMusic
bool yape_load_sound(char * sound_file, yape_audio * sound);
void yape_free_sound(yape_audio * sound);
bool yape_play_sound(yape_audio * sound);

#define yape_audio_quit Mix_CloseAudio


#endif //YAPE_AUDIO_H

