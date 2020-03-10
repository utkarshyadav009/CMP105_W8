#include "Level.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;



	// initialise game objects
	//t.loadFromFile("gfx/Beach_Ball.png");
	//t1.loadFromFile("gfx/Beach_Ball.png");
	//c.setInput(input);
	//c.setTexture(&t);
	//c.setSize(sf::Vector2f(100, 100));
	//c.setPosition(100, 100);
	//c.setVelocity(500.0, 500.0);

	//c1.setInput(input);
	//c1.setTexture(&t);
	//c1.setSize(sf::Vector2f(100, 100));
	//c1.setPosition(600, 100);
	//c1.setVelocity(500.0, 500.0);



	//s1.setSize(sf::Vector2f(50, 50));
	//s1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	//s1.setPosition(0, 200);
	//s1.setVelocity(200, 0);
	//s1.setFillColor(sf::Color::Blue);

	//s2.setPosition(750, 200);
	//s2.setSize(sf::Vector2f(50, 50));
	//s2.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	//s2.setVelocity(-200, 0);
	//s2.setFillColor(sf::Color::Green);

	t.loadFromFile("gfx/Beach_Ball.png");
	b.setInput(input);
	b.setWindow(window);
	b.setTexture(&t);
	b.setSize(sf::Vector2f(100, 100));
	b.setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	b.setPosition(700, 300);
	//b.setVelocity(500.0, 500.0);
	


	p2.setWindow(window);
	p2.setPosition(1150, 200);
	p2.setSize(sf::Vector2f(20, 200));
	p2.setCollisionBox(sf::FloatRect(0, 0, 20, 200));
	p2.setVelocity(-200, 0);
	p2.setFillColor(sf::Color::Green);

	p1.setWindow(window);
	p1.setPosition(20, 200);
	p1.setSize(sf::Vector2f(20, 200));
	p1.setCollisionBox(sf::FloatRect(0, 0, 20, 200));
	p1.setVelocity(-200, 0);
	p1.setFillColor(sf::Color::Green);




}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::S))
	{
		p1.update_p(dt);
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		p1.update_p(-dt);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		p2.update_p(dt);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		p2.update_p(-dt);
		
	
	}
}

// Update game objects
void Level::update(float dt)
{
	//c.update(dt); 
	//c1.update(-dt); 
	//if (Collision::checkBoundingCircle(&c, &c1)) 
	//{ c.collisionResponse(NULL); 
	//c1.collisionResponse(NULL); }
	//if (c.getPosition().x + c.getSize().x >= window->getSize().x || c.getPosition().x < 0)
	//{
	//	c.aftercollison(dt);
	//}

	//if (c1.getPosition().x + c1.getSize().x >= window->getSize().x || c1.getPosition().x < 0)
	//{
	//	c1.aftercollison(dt);
	//}

	/*s1.update(dt);
	s2.update(dt);
	if (Collision::checkBoundingBox(&s1, &s2))
	{
		std::cout << "COOL\n";
		s1.collisionResponse(NULL); 
	  s2.collisionResponse(NULL); 
	}*/



	b.update(dt);


	if ( Collision::checkBoundingBox(&b, &p1))
	{
		std::cout << "WOW\n";
		b.collisionResponse(NULL);
		
	}
	if (Collision::checkBoundingBox(&b, &p2))
	{
		std::cout << "COOL\n";
		b.collisionResponse(NULL);

	}
}

// Render level
void Level::render()
{
	beginDraw();
	//window->draw(c);
	//window->draw(c1);
	//window->draw(s1);
	//window->draw(s2);
	window->draw(b);
	window->draw(p1);
	window->draw(p2);
	b.drawDebugCollision(window);
	p1.drawDebugCollision(window);
	p2.drawDebugCollision(window);
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