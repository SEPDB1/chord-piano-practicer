#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include "Renderer.h"

int main()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw std::runtime_error(std::string("Failed to initialise SDL: ") + SDL_GetError());
	
	Renderer& r{ Renderer::GetInstance() };
	r.Init();
	
	bool isRunning = true;
	SDL_Event e;
	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_EVENT_QUIT:
				isRunning = false;
				break;
			}
		}

		r.Render();
	}

	SDL_Quit();
	return 0;
}
