#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Circle_Collisions :
	public GameObject
{

	sf::Vector2f gravity;
	sf::Vector2f velocity;
	

public:
	Circle_Collisions();
	~Circle_Collisions() {};
	void collisionResponse(GameObject* collider);
	void update(float dt);
	void aftercollison(float dt);
	sf::RenderWindow* window;

};

