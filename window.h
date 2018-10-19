#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>

#include "macro.h"

//Window macros/variables
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define SCALE_FACTOR 2 
#define FULLSCREEN false


//Window and renderer
extern SDL_Window* _window; 
extern SDL_Renderer* _renderer; 

//Quit flag
extern bool quit;

//////////////
void init(); //INITIALIZE

void _input(SDL_Event e); //GET INPUT

void _draw(); //DRAW TO SCREEN

void _close(); //CLOSE PROGRAM
//////////////

#endif //WINDOW_H_
