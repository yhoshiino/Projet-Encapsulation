#include "Key.h"
#include <iostream>
using namespace std;

Key::Key(const Texture& texture, const Vector2f& spawnPoint)
	: Object(texture), position(spawnPoint) {
	sprite.setPosition(position); // Place le sprite à la position de la clé
}

Key::~Key() {
	cout << "Clé détruite." << std::endl;
}

void Key::interact(Player& player) {
	player.addKey();
	cout << "Le joueur a ramassé une clé !" << std::endl;
}

void Key::update(float deltaTime) {
}

void Key::draw(RenderWindow& window) {
	window.draw(sprite);
}

