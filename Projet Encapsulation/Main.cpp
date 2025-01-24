#include <iostream>
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Map.h"
using namespace std;
using namespace sf;
const float tilesize = 16.f;
EntityManager* manager = EntityManager::getInstance();

int main() {
	Texture J1;
	Texture goldenKey;
	Texture Patroller;
	Texture Pot;
	Texture Chaser;
	Clock clock;
	float DeltaTime;
	Font font;
	

	if (!J1.loadFromFile("slime.png")) {
		cout << "introuvable";
		return -1;
	}
	if (!Patroller.loadFromFile("Chaser.png")) {
		cout << "Introuvable";
		return -1;
	}
	if (!Chaser.loadFromFile("Fantome-de-la-Fraude.png")) {
		cout << "Introuvable";
		return -1;
	}
	if (!Pot.loadFromFile("Potion.png")) {
		cout << "introuvable";
		return -1;
	}
	if (!goldenKey.loadFromFile("Key.png")) {
		cout << "introuvable";
		return -1;
	}
	if (!font.loadFromFile("Mario-Kart-DS.ttf")) {
		cout << "introuvable";
		return -1;
	}
	RenderWindow window(VideoMode(Width, Height), "Escape the dungeon");
	Event event;
	Map map("MAP.txt");
	
	manager->createChasers(Chaser, Vector2f(200, 200), 1.5f);
	manager->createPatrollers(Patroller, Vector2f(950, 500), 250.f);
	manager->createPatrollers(Patroller, Vector2f(0, 350), 250.f);
	manager->createPatrollers(Patroller, Vector2f(950, 250), 350.f);
	manager->createPatrollers(Patroller, Vector2f(950, 350), 250.f);
	manager->createPatrollers(Patroller, Vector2f(950, 600), 250.f);
	manager->createPotions(Pot, Vector2f(400, 400));
	manager->createKeys(goldenKey, Vector2f(83, 265));
	manager->createPlayers(J1, Vector2f(Width / 2, Height / 2), 5.f);

	Text Keycount("Key count: ", font, 50);
	while (window.isOpen()) {
		Keycount.setString(" X " + to_string(manager->Players[0]->getKey()));
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

		}
		window.setFramerateLimit(60);
		DeltaTime = clock.restart().asSeconds();
		manager->update(DeltaTime, map.getMap());
		manager->collisions(); 
		window.clear();
		map.draw(window);
		manager->draw(window);
		window.draw(Keycount);

		window.display();
	}




}