all:
	g++ -Iinclude -Llib/SDL2 -Llib/SDL2_image -Llib/SDL2_mixer -Llib/SDL2_ttf -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf