#include "Player.h"

Player::Player(const Texture& texture, const Vector2f& startPosition, float initialSpeed)
    : Entity(texture), position(startPosition), speed(initialSpeed) {
    sprite.setPosition(position);
}

Player::~Player() {
}



void Player::handleInput(float deltaTime, vector<string>& map) {

    if (sf::Keyboard::isKeyPressed(Keyboard::Z) && position.y > 0) {
        position.y = position.y - (float)speed;
    }
    if (sf::Keyboard::isKeyPressed(Keyboard::S) && position.y < 965) {
        position.y = position.y + (float)speed;
    }
    if (sf::Keyboard::isKeyPressed(Keyboard::Q) && position.x > 0) {
        position.x = position.x - (float)speed;
    }
    if (sf::Keyboard::isKeyPressed(Keyboard::D) && position.x < 1400) {
        position.x = position.x + (float)speed;
    }
}

void Player::update(float deltaTime) {
    position += velocity * deltaTime;
    sprite.setPosition(position);
}

void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}

const sf::Vector2f& Player::getPosition() const {
    return position;
}

const sf::Vector2f& Player::getVelocity() const {
    return velocity;
}

void Player::setPosition(const Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

void Player::setVelocity(const Vector2f& newVelocity) {
    velocity = newVelocity;
}

void Player::boost() {
    speed += 2.5f;
}

void Player::addKey() {
	keyCount++;
}

int Player::getKey() {
	return keyCount;
}