#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include"Circle_Collisions.h"
#include"AABB_collision.h"
#include"pong.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	Circle_Collisions c;
	Circle_Collisions c1;
	AABB_collision s1;
	AABB_collision s2;
	pong b;
	pong p1;
	pong p2;
	sf::Texture t;
	sf::Texture t1;
	sf::Vector2f velocity;
};