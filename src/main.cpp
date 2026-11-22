#include <iostream>
#include <SDL3/SDL.h>
#include "game.h"

int main()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw std::runtime_error(std::string("Failed to initialise SDL: ") + SDL_GetError());
	
	Game game{};
	bool isRunning = true;
	SDL_Event e;
	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_EVENT_KEY_UP:
				game.HandleButtonUp(e.key);
				break;
			case SDL_EVENT_KEY_DOWN:
				game.HandleButtonDown(e.key);
				break;
			case SDL_EVENT_MOUSE_BUTTON_UP:
				game.HandleMouseButtonUp(e.button);
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				game.HandleMouseButtonDown(e.button);
				break;
			case SDL_EVENT_MOUSE_MOTION:
				game.HandleMouseMotion(e.motion);
				break;
			case SDL_EVENT_QUIT:
				isRunning = false;
				break;
			}
		}

		game.Update();
		game.Render();
	}

	SDL_Quit();
	return 0;
}
