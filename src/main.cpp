#include <iostream>
#include <algorithm>

#include <SDL2/SDL.h>
#include "game.h"

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

int main(int argc, char* argv[]) {
	(void) argc; (void) argv;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized!" << std::endl
				  << "SDL_Error: " << SDL_GetError() << std::endl;
		return 0;
	}

#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
	// Disable compositor bypass
	if (!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0")) {
		std::cout << "SDL can not disable compositor bypass!" << std::endl;
		return 0;
	}
#endif

	// Create window
	SDL_Window *window = SDL_CreateWindow("Någonting",
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  SCREEN_WIDTH, SCREEN_HEIGHT,
										  SDL_WINDOW_SHOWN);
	if (!window) {
		std::cout << "Window could not be created!" << std::endl
				  << "SDL_Error: " << SDL_GetError() << std::endl;
	} else {
		// Create renderer
		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer) {
			std::cout << "Renderer could not be created!" << std::endl
					  << "SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			bool quit = false;

			while (!quit) {
				SDL_Event e;
				SDL_WaitEvent(&e);

				if (e.type == SDL_QUIT) quit = true;

				game_update(e);

				SDL_SetRenderDrawColor(renderer, 0xAA, 0xAA, 0xAA, 0xFF);

				SDL_RenderClear(renderer);

				game_draw(renderer);

				SDL_RenderPresent(renderer);
			}

			SDL_DestroyRenderer(renderer);
		}

		SDL_DestroyWindow(window);
	}

	SDL_Quit();
	return 0;
}
