#include "Enemy.h"


Enemy::Enemy(const Texture& texture, const Vector2f& startPosition, float initialSpeed)
    : Entity(texture), position(startPosition), speed(initialSpeed) {
    sprite.setPosition(position);
}

void Enemy::update(float deltaTime) {
    position += velocity * deltaTime;
    sprite.setPosition(position);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

const sf::Vector2f& Enemy::getPosition() const {
    return position;
}

const sf::Vector2f& Enemy::getVelocity() const {
    return velocity;
}

void Enemy::setPosition(const Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

void Enemy::setVelocity(const Vector2f& newVelocity) {
    velocity = newVelocity;
}