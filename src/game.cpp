#include <SDL2/SDL.h>

SDL_Rect playerRect = {0,0,100,100};

void game_update(SDL_Event e) {
	int mX, mY;

	SDL_GetMouseState(&mX, &mY);
	playerRect.x = mX - 50;
	playerRect.y = mY - 50;

	playerRect.w = mX;
	playerRect.h = mY;
}

void game_draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0xAA, 0x22, 0x22, 0xFF);
	SDL_RenderFillRect(renderer, &playerRect);
}
