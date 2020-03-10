#pragma once
#include "Framework/GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class pong :
	public GameObject
{
	float speed = 300.f;
	public:
		pong() ;
		void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
		sf::RenderWindow* window;
		sf::Vector2f bvelocity;
		void update(float dt);
		void update_p(float dt);
		void collisionResponse(GameObject* collider);
		bool checkBoundingBox(GameObject* ball, GameObject* bat);
		void stop(float dt);

};

