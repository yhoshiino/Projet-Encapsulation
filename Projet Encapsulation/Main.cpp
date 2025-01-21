#include <iostream>
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
using namespace std;
using namespace sf;

EntityManager* manager = EntityManager::getInstance();

int main() {
	Texture J1;
	Texture ChaseEnemy;
	Texture Pot;
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
	if (!Pot.loadFromFile("Potion.png")) {
		cout << "introuvable";
		return -1;
	}
	RenderWindow window(VideoMode(Width, Height), "Escape the dungeon");
	Event event;
	manager->createPlayers(J1, Vector2f(Width / 2, Height / 2), 5.f);
	manager->createChasers(ChaseEnemy, Vector2f(200, 200), 1.5f);
	manager->createPatrollers(ChaseEnemy, Vector2f(100, 100), 250.f);
	manager->createPotions(Pot, Vector2f(400, 400));
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

		}
		window.setFramerateLimit(60);
		DeltaTime = clock.restart().asSeconds();
		manager->update(DeltaTime);
		
		/*manager->collisions();*/
		window.clear();
		manager->draw(window);
		window.display();
	}




}