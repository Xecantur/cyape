#include "audio.h"


bool yape_audio_init(yape_audio_settings * settings){
	if(Mix_Init(YAPE_AUDIO_SUPPORTED) != YAPE_AUDIO_SUPPORTED){
		printf("SDL_Mixer Failed to initialize support for YAPE_AUDIO_FORMAT\n");
		printf("SDL_Mixer: %s\n",Mix_GetError());
		return false;
	}
	if(Mix_OpenAudio(settings->freq,settings->format,
			   settings->channels,settings->chunksize) == -1){
		printf("Mixer OpenAudio: %s\n " ,Mix_GetError());
		return false;
	}
	return true;
}

bool yape_load_music(char * music_file, yape_audio * music){
	music->filename = music_file;
	music->music = Mix_LoadMUS(music->filename);
	if(!music->music){
		printf("Unable to load Music File %s\n",music->filename);
		return false;
	}
	return true;
}

bool yape_load_sound(char * sound_file, yape_audio * sound){
	sound->filename = sound_file;
	sound->sound_clip = Mix_LoadWAV(sound->filename);
	if(!sound->sound_clip){
		printf("Unable to load Sound File %s\n",sound->filename);
		return false;
	}
	return true;
}

bool yape_play_music(yape_audio * music){
	if(Mix_PlayMusic(music->music,1) == -1){
		printf("Unable to play Music %s\n",music->filename);
		return false;
	}
	return true;
}

bool yape_play_sound(yape_audio * sound){
	if(Mix_PlayChannel(sound->channel, sound->sound_clip, 0)==-1) {
		    printf("Mix_PlayChannel: %s\n",Mix_GetError());
		    return false;
	}
	return true;
}

void yape_free_music(yape_audio * music){
	Mix_FreeMusic(music->music);
}
void yape_free_sound(yape_audio * sound){
	Mix_FreeChunk(sound->sound_clip);
}
