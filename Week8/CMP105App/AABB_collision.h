#pragma once
#include "Framework/GameObject.h"
#include"Framework/Collision.h"
#include"Framework/Vector.h"
class AABB_collision :
	public GameObject
{
	//sf::RectangleShape square1;
	//sf::RectangleShape square2;

	public:

		GameObject square1;
		GameObject square2;
		AABB_collision();
		void update(float dt);
		void collisionResponse(GameObject* collider);
		bool checkBoundingBox(GameObject* square1, GameObject* square2);

};

