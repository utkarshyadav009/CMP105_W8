#include "AABB_collision.h"
AABB_collision::AABB_collision()
{
	
}

void AABB_collision::update(float dt)
{
	move(velocity * dt); 
	if (getPosition().x < 0)
	{ setPosition(0, getPosition().y);
	velocity.x = -velocity.x; 
	}
	if (getPosition().x > 750)
	{ setPosition(750, getPosition().y); 
	velocity.x = -velocity.x; 
	}

}

bool AABB_collision::checkBoundingBox(GameObject* square1, GameObject* square2)
{
	if (square1->getCollisionBox().left + square1->getCollisionBox().width < square2->getCollisionBox().left)
		return false;
	
	if (square1->getCollisionBox().left > square2->getCollisionBox().left + square2->getCollisionBox().width)
		return false; 
	
	if (square1->getCollisionBox().top + square1->getCollisionBox().height < square2->getCollisionBox().top)
		return false; 
	
	if (square1->getCollisionBox().top > square2->getCollisionBox().top + square2->getCollisionBox().height)
		return false;
	
	else
	return true;


}

void AABB_collision::collisionResponse(GameObject* collider)
{
	velocity = -velocity;
}