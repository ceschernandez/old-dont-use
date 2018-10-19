#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "window.h"



int main( int argc, char* args[] )
{
	init();
	
	SDL_Event e;

	while(!quit)
	{
		_input(e);

		_draw();
	}


	_close();

	return 0;
}
