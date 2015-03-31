OBJ = main.c src/include/graphics.c
CFLAGS = -Wall -std=c11 -Isrc/ -Isrc/include/
LFLAGS = -lSDL2_image -lfreetype -lSDL2_ttf
BIN="cyape-1.0"
CC=clang
all:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/${BIN}

debug:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/${BIN} -g -DDEBUG -Wextra

release:
	${CC} src/${OBJ} ${CFLAGS} ${SDL_FLAGS} ${LFLAGS} -o ${BIN} -02 -DNO_WARNINGS
