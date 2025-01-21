#include "Patrolling.h"

Patrolling::Patrolling(const Texture& texture, const Vector2f& SpawnPosition, float speed)
    : Enemy(texture, SpawnPosition, speed),
    startPosition(SpawnPosition),                      // Position initiale de d�part
    endPosition(SpawnPosition.x + 200.f, SpawnPosition.y), // Exemple : 200 pixels plus loin
    movingToEnd(true)                                  // D�but du mouvement vers endPosition
{
    sprite.setPosition(startPosition); // Met le sprite � la position de d�part
    velocity = Vector2f(speed, 0.f);  // Initialisation de la vitesse
    cout << "Position de d�part : " << position.x << endl;
}



void Patrolling::update(float deltaTime)
{
    // Mise � jour de la position en fonction de la vitesse
    position += velocity * deltaTime;

    // V�rifier si l'ennemi atteint une extr�mit� de la patrouille
    if (movingToEnd && position.x >= endPosition.x) {
        movingToEnd = false; // Change de direction
        velocity.x = -std::abs(velocity.x); // Se d�place vers la gauche
    }
    else if (!movingToEnd && position.x <= startPosition.x) {
        movingToEnd = true; // Change de direction
        velocity.x = std::abs(velocity.x); // Se d�place vers la droite
    }
    // Mettre � jour la position du sprite
    this->getSprite().setPosition(position);
}

void Patrolling::draw(RenderWindow& window) 
{
    window.draw(sprite);
}


void Patrolling::collisions(Player& player) {
    FloatRect hitboxPlayer = player.getSprite().getGlobalBounds();
    FloatRect hitboxChaser = this->getSprite().getGlobalBounds();
    if (hitboxChaser.intersects(hitboxPlayer)) {
        player.~Player();
    }
}