#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include "common.h"
//Generated with genfile -d graphics.h -i "['common.h']"

//! \file
//! \brief the graphics module

//! \brief y_pprect prints out an SDL_Rect's members used for debugging
void y_pprect(SDL_Rect * rect); //print pointer rect

/*------------------Window-----------------------------*/
//! \brief Data type for handling SDL Windows
struct y_window{
	SDL_Window * window;
	char * name;
	int done;
	SDL_Renderer * rnd;
	SDL_Rect loc;
};

typedef struct y_window y_window;

/*------------------------Texture-----------------------------*/
//! \brief Data type for handling SDL Textures
struct y_texture{
	SDL_Rect loc;
	SDL_Texture * image;
	char * name;
	SDL_Renderer * rnd;
};

typedef struct y_texture y_texture;

//! \brief loads textures into array t_list (hint use &array for t_list)
void y_load_textures(char ** a_list, uint8_t n_textures, y_texture * t_list, SDL_Renderer * rnd);
//! \fn y_load_textures(char ** a_list, uint8_t n_textures, y_texture * t_list, SDL_Renderer * rnd);
//! \param a_list list of textures to load into t_list
//! \param n_textures number of textures to load
//! \param t_list the texture array to store textures(the type)
//! \param rnd the Renderer to use

//! \brief load a single texture returns a y_texture
y_texture y_load_texture(char * name, SDL_Renderer * rnd);
//! \fn y_load_texture(char * name, SDL_Renderer * rnd)
//! \param name the path to texture you want to load
//! \param rnd the Renderer to use
/*-----------------------Text-------------------------------*/
//! \brief Data Type for handling True Type Text (SDL_Texture)
struct y_label{
	char * text;
	int font_size;
	SDL_Color color;
	SDL_Texture * image;
	TTF_Font * font;
	SDL_Rect loc;
};

typedef struct y_label y_label;

//! \brief makes a label (a Texture out of text) returns a y_label
y_label y_make_label(char * text, SDL_Color color, TTF_Font * font, SDL_Renderer * rnd);
//! \fn y_make_label(char * text, TTF_Font * font, int w, int h, SDL_Color color, SDL_Renderer * rnd);
//! \param text the text to go on the label
//! \param font the font to use (should be loaded prior to calling this function)
//! \param w width of text
//! \param h height of text
//! \param color color of text
//! \param rnd the Renderer to use
/*------------------------y_button----------------------------*/

struct y_button {
	y_texture img;
	y_label  label;
};

typedef struct y_button y_button;

y_button y_make_button(char * text, char * button_img, TTF_Font * font, SDL_Renderer * rnd);
#endif //__GRAPHICS_H__
