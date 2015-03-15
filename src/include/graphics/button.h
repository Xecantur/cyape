#ifndef BUTTON_H
#define BUTTON_H
#include "../common.h"
#include "texture.h"
#include "label.h"
//Generated with genfile -d button.h -i "['../common.h']"


struct y_button {
	y_img img;
	y_label label;
};

typedef struct y_button y_button;


#endif //BUTTON_H
