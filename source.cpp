#include "D:/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "hero.h"

sf::Vector2f viewSize(1747, 1240);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFMLGame !!!",sf::Style::Default);
sf::Texture skyTexture;
sf::Sprite skySprite;
sf::Vector2f playerPosition;
bool playerMoving = false;
hero Hero;

void init() {
	skyTexture.loadFromFile("Assets/graphics/background.png");
	skySprite.setTexture(skyTexture);
	Hero.init("Assets/graphics/hero.png", sf::Vector2f(viewSize.x *
		0.25f, viewSize.y * 0.5f), 200);
}

void draw() {
	window.draw(skySprite);
	window.draw(Hero.getSprite());
}

void updateInput() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				Hero.jump(750.0f);
			}
		}
		if (event.key.code == sf::Keyboard::Escape || event.type ==
			sf::Event::Closed)
			window.close();
	}
}

void update(float dt) {
	Hero.update(dt);
}

int main() {
	sf::Clock clock;
	init();
	while (window.isOpen()) {
		updateInput();
		sf::Time dt = clock.restart();
		update(dt.asSeconds());
		window.clear(sf::Color::Red);
		draw();
		window.display();
	}
	return 0;
}