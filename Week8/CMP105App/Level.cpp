#include "Level.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	t.loadFromFile("gfx/Beach_Ball.png");
	t1.loadFromFile("gfx/Beach_Ball.png");
	c.setInput(input);
	c.setTexture(&t);
	c.setSize(sf::Vector2f(100, 100));
	c.setPosition(100, 100);
	c.setVelocity(500.0, 500.0);

	c1.setInput(input);
	c1.setTexture(&t);
	c1.setSize(sf::Vector2f(100, 100));
	c1.setPosition(600, 100);
	c1.setVelocity(500.0, 500.0);

	




}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	c.update(dt); 
	c1.update(-dt); 
	if (Collision::checkBoundingCircle(&c, &c1)) 
	{ c.collisionResponse(NULL); 
	c1.collisionResponse(NULL); }
	if (c.getPosition().x + c.getSize().x >= window->getSize().x || c.getPosition().x < 0)
	{
		c.aftercollison(dt);
	}

	if (c1.getPosition().x + c1.getSize().x >= window->getSize().x || c1.getPosition().x < 0)
	{
		c1.aftercollison(dt);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(c);
	window->draw(c1);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}