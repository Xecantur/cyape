OBJ = src/unit/main.c src/include/common.c src/include/audio.c
OBJ2= src/include/graphics/texture.c src/include/graphics/label.c src/include/graphics/button.c src/include/graphics/menu.c
OBJS= ${OBJ} ${OBJ2} 
CFLAGS =  -Weverything -Wno-documentation -Wno-padded -Wno-c++-compat -std=c11 -Isrc/ -Isrc/include/ -I/usr/include/SDL2 -D_REENTRANT 
RLFLAGS = -L/usr/lib -lSDL2 -lpthread -lfreetype -lSDL2_ttf -lSDL2_image -lvorbis -lSDL2_mixer -llua -lm -ljansson -lchipmunk
BIN="cyape-1.5"
CC=clang
all:
	${CC} ${OBJS} ${CFLAGS} ${RLFLAGS} -o `pwd`/${BIN} 
	${CC} ${OBJS} ${CFLAGS} -g ${RLFLAGS} -o `pwd`/${BIN}.debug 

debug:
	${CC} ${OBJS} ${CFLAGS} -g ${RLFLAGS} -o `pwd`/${BIN}.debug -g -DDEBUG

release:
	${CC} ${OBJS} ${CFLAGS} ${RLFLAGS} -o ${BIN} -O2 -DNO_WARNINGS
