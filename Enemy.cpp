#include <Enemy.h>

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}



void Enemy::clean()
{

}

void Enemy::update()
{
	m_x += 1;
	
}