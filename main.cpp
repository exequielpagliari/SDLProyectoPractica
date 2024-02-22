#include "Game.h"
#include <stdio.h>
#include "iostream"
#include "SDL.h"
// our Game object

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;
	std::cout << "game init attempt...\n";
	if (Game::Instance()->init("Chapter 1", 100, 100, 800, 600,
		false))
	{
		while (Game::Instance()->running())
		{
			frameStart = SDL_GetTicks();
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}

		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
		Game::Instance()->clean();
		return 0;
	


}