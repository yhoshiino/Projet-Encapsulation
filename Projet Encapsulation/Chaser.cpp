#include "Chaser.h"
Chaser::Chaser(const Texture& texture, const Vector2f& SpawnPosition, float speed) : Enemy(texture, SpawnPosition, speed) {
    sprite.setPosition(position);
    cout << position.x << endl;
}

Chaser::~Chaser() {

}


void Chaser::updateDirection(Player& player)
{
    // Récupérer les positions actuelles
    Vector2f playerPosition = player.getSprite().getPosition();
    Vector2f chaserPosition = this->getSprite().getPosition();

    // Calculer la direction vers le joueur
    Vector2f direction = playerPosition - chaserPosition;

    // Normaliser la direction (éviter des déplacements trop rapides)
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0) {
        direction.x /= magnitude;
        direction.y /= magnitude;
    }

    // Appliquer la direction à la vitesse actuelle
    this->velocity.x = direction.x * this->speed;
    this->velocity.y = direction.y * this->speed;

    // Mettre à jour la position
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;

    // Mettre à jour la position du sprite
    this->getSprite().setPosition(this->position);
}



void Chaser::update(float deltaTime) 
{
    this->getSprite().move(coordX, coordY * speed * deltaTime);
}

void Chaser::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

const sf::Vector2f& Chaser::getPosition() const {
    return position;
}

const sf::Vector2f& Chaser::getVelocity() const {
    return velocity;
}

void Chaser::setPosition(const Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

void Chaser::setVelocity(const Vector2f& newVelocity) {
    velocity = newVelocity;
}

void Chaser::collisions(Player& player) {
    FloatRect hitboxPlayer = player.getSprite().getGlobalBounds();
    FloatRect hitboxChaser = this->getSprite().getGlobalBounds();
    if (hitboxChaser.intersects(hitboxPlayer)) {
        player.~Player();
    }

}