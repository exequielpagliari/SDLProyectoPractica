
#include <stdio.h>
#include "iostream"
#include "SDL_image.h"
#include "TextureManager.h"
#include <Tortuga.h>
#include <Enemy.h>
#include "GameObject.h"
#include "Game.h"


int m_currentFrame;



	bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
	{
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		// attempt to initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "SDL init success\n";
			// init the window
			m_pWindow = SDL_CreateWindow(title, xpos, ypos,
				width, height, flags);
			if (m_pWindow != 0) // window init success
			{
				std::cout << "window creation success\n";
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
				if (m_pRenderer != 0) // renderer init success
				{
					std::cout << "renderer creation success\n";
					SDL_SetRenderDrawColor(m_pRenderer,
						255, 0, 0, 255);
				}
				else
				{
					std::cout << "renderer init fail\n";
					return false; // renderer init fail
				}
			}
			else
			{
				std::cout << "window init fail\n";
				return false; // window init fail
			}
		}
		else
		{
			std::cout << "SDL init fail\n";
			return false; // SDL init fail
		}
		std::cout << "init success\n";
		m_bRunning = true; // everything inited successfully, start the main loop

		TextureManager::Instance()->load("Assets/player_sheet.png", "animate", m_pRenderer);
		
		

		m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 128, 82,
			"animate")));

		m_gameObjects.push_back(new Tortuga(new LoaderParams(100, 200, 64, 64+8,
			"animate")));

		return true;
	}


	void Game::render()
	{
		SDL_RenderClear(m_pRenderer); // clear to the draw colour
		for (std::vector<GameObject*>::size_type i = 0; i !=
			m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->draw();
		}
		
		SDL_RenderPresent(m_pRenderer); // draw to the screen
	

	}

	void Game::handleEvents()
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
			}
		}
	}


	void Game::clean()
	{
		std::cout << "cleaning game\n";
		SDL_DestroyWindow(m_pWindow);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_Quit();
	}

	std::vector<GameObject*> m_gameObjects;
	void Game::update()
	{
		
		for (std::vector<GameObject*>::size_type i = 0; i !=
			m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
		}
		
	}

	Game* Game::s_pInstance = nullptr;

	Game* Game::Instance() {
		if (s_pInstance == nullptr) {
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	