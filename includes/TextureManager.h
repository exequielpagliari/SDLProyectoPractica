#pragma once
#include "SDL_image.h"
#include "SDL.h"
#include "string"
#include "map"
#include <stdio.h>

using namespace std;


class TextureManager
{
public:


	static TextureManager* Instance();

	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	// draw
	void draw(std::string id, int x, int y, int width, int
		height, SDL_Renderer* pRenderer, SDL_RendererFlip flip =
		SDL_FLIP_NONE);
	// drawframe
	void drawFrame(std::string id, int x, int y, int width, int
		height, int currentRow, int currentFrame, SDL_Renderer*
		pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	std::map<std::string, SDL_Texture*> m_textureMap;


private:
	static TextureManager* s_pInstance;
	TextureManager() {}
	

	
	
};

