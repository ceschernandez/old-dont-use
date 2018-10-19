#ifndef MACRO_H_
#define MACRO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/////////////
typedef struct
{
	int x, y;
} _Point;
/////////////
typedef struct
{
	SDL_Texture* texture;
	SDL_Rect rect;
	int x;
	int y;
} _Sprite;


/////////////
SDL_Texture* loadTexture(SDL_Renderer* renderer, char* path);

_Sprite _SpriteLoad(SDL_Renderer* renderer, char* path);

_Sprite _SpriteTextCreate(SDL_Renderer* renderer, TTF_Font* font, char* text, SDL_Color color);

void _SpriteDraw(SDL_Renderer* renderer, _Sprite sprite);
void _SpriteDrawPosition(SDL_Renderer* renderer, _Sprite sprite, int x, int y);

void _SpriteUnload(_Sprite sprite);


#endif //MACRO_H_















