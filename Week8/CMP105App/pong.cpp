#include "pong.h"
void pong::update(float dt)
{
	bvelocity = sf::Vector2f(300, 0);
	move(bvelocity*dt);
	
}

void pong::update_p(float dt)
{
	velocity = sf::Vector2f(0, 200);
	move(velocity * dt);

}
bool pong::checkBoundingBox(GameObject* ball , GameObject* bat)
{
	if (ball->getCollisionBox().left + ball->getCollisionBox().width < bat->getCollisionBox().left)
		return false;

	if (ball->getCollisionBox().left > bat->getCollisionBox().left + bat->getCollisionBox().width)
		return false;

	if (ball->getCollisionBox().top + ball->getCollisionBox().height < bat->getCollisionBox().top)
		return false;

	if (ball->getCollisionBox().top > bat->getCollisionBox().top + bat->getCollisionBox().height)
		return false;

	else
		return true;


}


void pong::collisionResponse(GameObject* collider)
{
	bvelocity = -bvelocity;
	
}
