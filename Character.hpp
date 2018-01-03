#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

class Character{
public:	
	Character();
	void update(float elapsed);
	void draw(sf::RenderWindow &w) const;

	const float FLOOR_LEVEL = 400;

private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	
	bool isTouchingFloor();
	void collideWithFloor();

	const float CHARACTER_SIZE = 64;
	const float CHARACTER_GRAVITY = 700;
	const float CHARACTER_MOVE_VEL = 200;
	const float CHARACTER_JUMP_VEL = 500;

};

#endif // __CHARACTER_HPP__
