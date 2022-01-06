#include <SDL2/SDL.h>

int playerX = 0;
int playerY = 0;

void game_update(SDL_Event e) {
	int x, y;
	int buttons;

	buttons = SDL_GetMouseState(&x, &y);
	playerX = x - 50;
	playerY = y - 50;
}

void game_draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

	SDL_Rect playerRect;
	playerRect.x = playerX;
	playerRect.y = playerY;
	playerRect.w = 100;
	playerRect.h = 100;

	SDL_RenderFillRect(renderer, &playerRect);
}
