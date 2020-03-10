#include "pong.h"
pong::pong()
{
	velocity = sf::Vector2f(1, 0);
}
void pong::update(float dt)
{
	std::cout << velocity.x << " " << velocity.y << "\n";
	//velocity = sf::Vector2f(300, 0);
	if (getPosition().x + getSize().x >= window->getSize().x || getPosition().x < 0)
	{
		velocity *= -1.f;
		//velocity = sf::Vector2f(-300, 0);
	}
	move(velocity*speed*dt);
	
}

void pong::update_p(float dt)
{
	velocity = sf::Vector2f(0, 200);
	if (getPosition().y + getSize().y >= window->getSize().y || getPosition().y < 0)
	{
		velocity = sf::Vector2f(0, -200);
	}
	move(velocity * dt);
	

}
void pong::stop(float dt)
{



}
bool pong::checkBoundingBox(GameObject* ball , GameObject* bat)
{
	return ball->getCollisionBox().intersects(bat->getCollisionBox());
}


void pong::collisionResponse(GameObject* collider)
{
	velocity = -velocity;
	
}
