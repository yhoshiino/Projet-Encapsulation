#include "Object.h"

Object::Object(const sf::Texture& texture) : Entity(texture) {

}


void Object::update(float deltaTime) {
}

void Object::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}