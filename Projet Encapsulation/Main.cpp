#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace std;
using namespace sf;


int main() {
	Texture J1;
	Clock clock;
	float DeltaTime;



	if (!J1.loadFromFile("slime.png")) {
		cout << "introuvable";
		return -1;
	}
	RenderWindow window(VideoMode(Width, Height), "Escape the dungeon");
	Event event;
	Player slime(J1, Vector2f(Width/2, Height/2), 5.f);
	

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

		}
		window.setFramerateLimit(144);
		DeltaTime = clock.restart().asSeconds();
		slime.handleInput();
		slime.update(DeltaTime);
		window.clear();
		slime.draw(window);
		window.display();
	}




}