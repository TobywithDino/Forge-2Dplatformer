all:
	g++ -Iinclude -Llib/SDL2 -Llib/SDL2_image -Llib/SDL2_mixer -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer