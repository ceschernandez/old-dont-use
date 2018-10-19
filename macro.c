///////////
//macro.c//
///////////
#include "macro.h"


/////////////
SDL_Texture* loadTexture(SDL_Renderer* renderer, char* path)
{
	SDL_Surface* surface = SDL_LoadBMP(path);
	SDL_Texture* texture = NULL;
	if(!surface)
	{
		printf("Error: Could not load image path %s", path);
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, surface);
	}
	SDL_FreeSurface(surface);

	return texture;
}

/////////////
_Sprite _SpriteLoad(SDL_Renderer* renderer, char* path)
{
	_Sprite sprite;
	sprite.texture = NULL;

	SDL_Surface* surface = SDL_LoadBMP(path);
	if(!surface)
	{
		printf("Error: Could not load image path %s", path);
	}
	else
	{
		sprite.texture = SDL_CreateTextureFromSurface(renderer, surface);
	}
	sprite.rect = (SDL_Rect){0, 0, surface->w, surface->h};	
	SDL_FreeSurface(surface);

	return sprite;
}

/////////////
_Sprite _SpriteTextCreate(SDL_Renderer* renderer, TTF_Font* font, char* text, SDL_Color color)
{
	_Sprite sprite;
	sprite.texture = NULL;

	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
	if(!surface)
	{
		printf("Error: Could not create text! %s", text);
	}
	else
	{
		sprite.texture = SDL_CreateTextureFromSurface(renderer, surface);
	}
	sprite.rect = (SDL_Rect){0, 0, surface->w, surface->h};	
	SDL_FreeSurface(surface);

	return sprite;

}

/////////////
void _SpriteDraw(SDL_Renderer* renderer, _Sprite sprite)
{
	SDL_Rect destRect = (SDL_Rect){sprite.x, sprite.y, sprite.rect.w, sprite.rect.h};
	SDL_RenderCopy(renderer, sprite.texture, &(sprite.rect), &destRect);
}

/////////////
void _SpriteDrawPosition(SDL_Renderer* renderer, _Sprite sprite, int x, int y)
{
	SDL_Rect destRect = (SDL_Rect){x, y, sprite.rect.w, sprite.rect.h};
	SDL_RenderCopy(renderer, sprite.texture, &(sprite.rect), &destRect);
}

/////////////
void _SpriteUnload(_Sprite sprite)
{
	SDL_DestroyTexture(sprite.texture);
	sprite.texture = NULL;
}











