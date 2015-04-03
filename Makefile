OBJ = main.c src/include/graphics.c src/include/audio.c
CFLAGS = -Weverything -Wno-documentation -Wno-padded -std=c11 -Isrc/ -Isrc/include/
LFLAGS = -lSDL2_image -lfreetype -lSDL2_ttf -lfmodex
BIN="cyape-1.0"
CC=clang
all:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/${BIN} -g

debug:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/${BIN} -g -DDEBUG

release:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o ${BIN} -O2 -DNO_WARNINGS
