#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Patrolling.h"
using namespace std;
using namespace sf;


int main() {
	Texture J1;
	Texture ChaseEnemy;
	Clock clock;
	float DeltaTime;



	if (!J1.loadFromFile("slime.png")) {
		cout << "introuvable";
		return -1;
	}
	if (!ChaseEnemy.loadFromFile("Chaser.png")) {
		cout << "Introuvable";
		return -1;
	}
	RenderWindow window(VideoMode(Width, Height), "Escape the dungeon");
	Event event;
	Player slime(J1, Vector2f(Width/2, Height/2), 5.f);
	Chaser Chaser1(ChaseEnemy, Vector2f(200, 200), 1.5f);
	Chaser1.getSprite().setScale(0.5f, 0.5f);
	Patrolling Patroller1(ChaseEnemy, Vector2f(100, 100), 1.5f);
	Patroller1.getSprite().setScale(0.5f, 0.5f);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

		}
		window.setFramerateLimit(144);
		DeltaTime = clock.restart().asSeconds();
		slime.handleInput();
		slime.update(DeltaTime);
		Chaser1.updateDirection(slime);
		Chaser1.update(DeltaTime);
		Chaser1.collisions(slime);
		Patroller1.update(DeltaTime);
		window.clear();
		slime.draw(window);
		Patroller1.draw(window);
		Chaser1.draw(window);
		window.display();
	}




}