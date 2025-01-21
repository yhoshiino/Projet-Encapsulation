#include "Entity.h"

Entity::Entity(const Texture& texture) {
    sprite.setTexture(texture);
}

Sprite& Entity::getSprite() {
    return sprite;
}

void Entity::setTexture(const Texture& texture) {
    sprite.setTexture(texture);
}

void Entity::draw(RenderWindow& window) {
    window.draw(sprite);
}
