#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;


void Movement(sf::Sprite &sprite,int speed,float Tiempo) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		sprite.move(-speed*Tiempo, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		sprite.move(speed*Tiempo, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
		sprite.move(0,-speed*Tiempo);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
		sprite.move(0,speed*Tiempo);
}


int main() {
	sf::RenderWindow window;
	sf::Texture texture;
	int speed = 30;
	
	window.create(sf::VideoMode(800, 600), "Ejemplo 1");
	if (!texture.loadFromFile("Assets/Azul.png"))
	{
		cout << "no cargo la textura " << endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::Clock clock;

	while (window.isOpen()){		
		

		window.clear();
		window.draw(sprite);
		window.display();

		sf::Time elapsed = clock.restart();
		Movement(sprite, speed, elapsed.asSeconds());

		sf::Event event;
	while (window.pollEvent(event)){						
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
	}
		return 0;
}

	