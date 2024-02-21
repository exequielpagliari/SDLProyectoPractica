
#pragma once
#ifndef __Game__
#define __Game__
#include "SDL.h"
#include "TextureManager.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include "GameObject.h"

using namespace std;

class Game
{
public:

	static Game* Instance();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	int m_currentFrame;
	std::vector<GameObject*> m_gameObjects;

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	static Game* s_pInstance;
	Game() {};
	// create the typedef
	typedef Game TheGame;
	bool m_bRunning;

	



};

#endif /* defined(__Game__) */