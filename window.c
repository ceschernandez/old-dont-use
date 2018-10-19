////////////
//window.c//
////////////

#include "window.h"


//Window and renderer
SDL_Window* _window = NULL; //(extern)
SDL_Renderer* _renderer = NULL; //(extern)

TTF_Font* font = NULL;
SDL_Color black = {0, 0, 0};

//Quit flag
bool quit = false; //(extern)



_Sprite text;


//////////////////
void init() //Initialize things
{ 
	SDL_Init( SDL_INIT_EVERYTHING );

	_window = SDL_CreateWindow( "SDLapp", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN ); 
	 
	if(FULLSCREEN) { SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN); }

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderSetScale(_renderer, SCALE_FACTOR, SCALE_FACTOR);


	TTF_Init();
	font = TTF_OpenFont("LiberationMono-Regular.ttf", 28);

	//Ex. code
	text = _SpriteTextCreate(_renderer, font, "asdf", black);
}

//////////////////
void _input(SDL_Event e)
{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if( e.type == SDL_KEYDOWN ) 
			{ 
				switch( e.key.keysym.sym ) 
				{ 
					case SDLK_ESCAPE:
						quit = true;
					       break;
				//Put events for different keypresses here
				}
			}
		}
}

//////////////////
void _draw()
{
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);
	/////////^^off limits


	//DRAW
	
	//Ex. code
	_SpriteDrawPosition(_renderer, text, 0, 0);
	

	/////////,,off limits
	SDL_RenderPresent(_renderer);
}

//////////////////
void _close()
{
	
	//Ex. code
	_SpriteUnload(text);

	TTF_CloseFont(font);

	/////////
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;

	SDL_DestroyWindow( _window );
	_window = NULL;

	SDL_AudioQuit();
	SDL_Quit();
}
