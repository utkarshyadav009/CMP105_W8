#include "Circle_Collisions.h"
Circle_Collisions::Circle_Collisions()
{
	velocity = sf::Vector2f(100, 0);
}
void Circle_Collisions::collisionResponse(GameObject* collider)
{
	velocity = sf::Vector2f(-100, 0);


}
void Circle_Collisions::update(float dt)
{
		
		move(velocity * dt);
		

	
}
void Circle_Collisions::aftercollison(float dt)
{
	velocity = sf::Vector2f(100, 0);
}