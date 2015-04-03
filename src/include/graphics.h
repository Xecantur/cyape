#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include "common.h"
//Generated with genfile -d graphics.h -i "['common.h']"

//! \file
//! \brief the graphics module

//! \brief yape_pprect prints out an SDL_Rect's members used for debugging
void yape_pprect(SDL_Rect * rect); //print pointer rect

/*------------------Window-----------------------------*/
//! \brief Data type for handling SDL Windows
struct yape_window{
	SDL_Window * window;
	char * name;
	int done;
	SDL_Renderer * rnd;
	SDL_Rect size;
};

typedef struct yape_window yape_window;

/*------------------------Texture-----------------------------*/
//! \brief Data type for handling SDL Textures
struct yape_texture{
	SDL_Rect size;
	SDL_Texture * image;
	char * name;
	SDL_Renderer * rnd;
};

typedef struct yape_texture yape_texture;

//! \brief loads textures into array t_list (hint use &array for t_list)
void yape_load_textures(char ** a_list, uint8_t n_textures, yape_texture * t_list, SDL_Renderer * rnd);
//! \fn yape_load_textures(char ** a_list, uint8_t n_textures, yape_texture * t_list, SDL_Renderer * rnd);
//! \param a_list list of textures to load into t_list
//! \param n_textures number of textures to load
//! \param t_list the texture array to store textures(the type)
//! \param rnd the Renderer to use

//! \brief load a single texture returns a yape_texture
yape_texture yape_load_texture(char * name, SDL_Renderer * rnd);
//! \fn yape_load_texture(char * name, SDL_Renderer * rnd)
//! \param name the path to texture you want to load
//! \param rnd the Renderer to use
/*-----------------------Text-------------------------------*/
//! \brief Data Type for handling True Type Text (SDL_Texture)
struct yape_label{
	char * text;
	int font_size;
	SDL_Color color;
	SDL_Texture * image;
	TTF_Font * font;
	SDL_Rect size;
};

typedef struct yape_label yape_label;

//! \brief makes a label (a Texture out of text) returns a yape_label
yape_label yape_make_label(char * text, TTF_Font * font, int w, int h, SDL_Color color, SDL_Renderer * rnd);
//! \fn yape_make_label(char * text, TTF_Font * font, int w, int h, SDL_Color color, SDL_Renderer * rnd);
//! \param text the text to go on the label
//! \param font the font to use (should be loaded prior to calling this function)
//! \param w width of text
//! \param h height of text
//! \param color color of text
//! \param rnd the Renderer to use
/*------------------------Menu----------------------------*/

#endif //__GRAPHICS_H__
