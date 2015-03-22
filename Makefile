OBJ = unit/main.c include/audio.c include/common.c
CFLAGS =  -Weverything -Wno-documentation -Wno-padded -Wno-c++-compat -std=c11 -Isrc/ -Isrc/include/
LFLAGS = -lfreetype -lSDL2_ttf -lSDL2_image -lvorbis -lSDL2_mixer -ljansson -lchipmunk
BIN="cyape-1.5"
CC=clang
all:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/${BIN} -g

debug:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/${BIN} -g -DDEBUG

release:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o ${BIN} -O2 -DNO_WARNINGS
