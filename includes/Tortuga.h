#pragma once
#include <SDLGameObject.h>
// Enemy class
class Tortuga : public SDLGameObject
{
public:
	Tortuga(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
}; 
