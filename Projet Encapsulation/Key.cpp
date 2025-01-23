#include "Key.h"
#include <iostream>
using namespace std;

Key::Key(const Texture& texture, const Vector2f& spawnPoint)
	: Object(texture), position(spawnPoint) {
	sprite.setPosition(position); // Place le sprite � la position de la cl�
}

Key::~Key() {
	cout << "Cl� d�truite." << std::endl;
}

void Key::interact(Player& player) {
	player.addKey();
	cout << "Le joueur a ramass� une cl� !" << std::endl;
}

void Key::update(float deltaTime) {
}

void Key::draw(RenderWindow& window) {
	window.draw(sprite);
}

