#include <SFML/Window/Keyboard.hpp>
#include "Character.hpp"
#include "Global.hpp"

Character::Character(){
	shape.setSize(sf::Vector2f(CHARACTER_SIZE, CHARACTER_SIZE));
	shape.setPosition((Global::WINDOW_WIDTH-CHARACTER_SIZE)/2.0, 100);
	shape.setFillColor(sf::Color(255, 65, 42));
}
	
void Character::update(float elapsed){
	// side movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		velocity.x = -CHARACTER_MOVE_VEL;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		velocity.x = CHARACTER_MOVE_VEL;
	}else{
		velocity.x = 0;
	}
		
	// is character is on the floor and up key is pressed then start jumping
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isTouchingFloor()){
		velocity.y = -CHARACTER_JUMP_VEL;
	}
		
	// apply gravity to vertical component of velocity
	velocity.y += CHARACTER_GRAVITY * elapsed;
		
	// move the character based on the calculated velocity
	shape.move(velocity*elapsed);

	// if touching floor again then fix position and reset velocity on y
	collideWithFloor();
}
	
void Character::draw(sf::RenderWindow &w) const {
	w.draw(shape);
}

	
bool Character::isTouchingFloor(){
	return shape.getPosition().y + shape.getSize().y >= FLOOR_LEVEL;
}
	
void Character::collideWithFloor(){
	if(isTouchingFloor()){
		// we must NOT change the x component of the position
		sf::Vector2f pos = shape.getPosition();
		pos.y = FLOOR_LEVEL - shape.getSize().y;
		shape.setPosition(pos);
		velocity.y = 0;
	}		
}