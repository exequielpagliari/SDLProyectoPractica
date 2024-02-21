#include "Game.h"
#include <stdio.h>
#include "iostream"
#include "SDL.h"
// our Game object



int main(int argc, char* argv[])
{
	std::cout << "game init attempt...\n";
	if (Game::Instance()->init("Chapter 1", 100, 100, 800, 600,
		false))
	{
		while (Game::Instance()->running())
		{
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			SDL_Delay(10);
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