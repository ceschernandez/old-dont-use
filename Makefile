all : *.c
	gcc *.c -o SDLapp -lSDL2 -lSDL2_ttf
	./SDLapp
