#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Character.hpp"
#include "Global.hpp"

int main(int argc, char *argv[]){
	sf::RenderWindow w(sf::VideoMode(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT),"Sprite jump");
	w.setFramerateLimit(60);
	
	Character hero;
	sf::RectangleShape floor;
	floor.setSize(sf::Vector2f(Global::WINDOW_WIDTH, 200));
	floor.setPosition(0, hero.FLOOR_LEVEL);
	floor.setFillColor(sf::Color(0, 178, 87));
	
	while(w.isOpen()) {
		sf::Event e;
		while(w.pollEvent(e)) {
			if(e.type == sf::Event::Closed)
				w.close();	
		}
		
		// 
		hero.update(1/60.0);
		
		// draw
		w.clear(sf::Color::White);
		hero.draw(w);
		w.draw(floor);
		w.display();
	}
	return 0;
}



