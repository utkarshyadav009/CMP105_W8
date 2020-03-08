#pragma once
#include "Framework/GameObject.h"

class pong :
	public GameObject
{
	
	public:
		sf::RenderWindow* window;
		GameObject ball;
		GameObject bat;
		sf::Vector2f bvelocity;
		void update(float dt);
		void update_p(float dt);
		void collisionResponse(GameObject* collider);
		bool checkBoundingBox(GameObject* ball, GameObject* bat);

};

