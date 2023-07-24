all:
	g++ -Iinclude -Llib/SDL2 -Llib/SDL2_image -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image