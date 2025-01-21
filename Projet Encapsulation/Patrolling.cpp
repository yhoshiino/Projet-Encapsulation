#include "Patrolling.h"

Patrolling::Patrolling(const Texture& texture, const Vector2f& SpawnPosition, float speed)
    : Enemy(texture, SpawnPosition, speed),
    startPosition(SpawnPosition),                      // Position initiale de départ
    endPosition(SpawnPosition.x + 200.f, SpawnPosition.y), // Exemple : 200 pixels plus loin
    movingToEnd(true)                                  // Début du mouvement vers endPosition
{
    sprite.setPosition(startPosition); // Met le sprite à la position de départ
    velocity = Vector2f(speed, 0.f);  // Initialisation de la vitesse
    cout << "Position de départ : " << position.x << endl;
}



void Patrolling::update(float deltaTime)
{
    // Mise à jour de la position en fonction de la vitesse
    position += velocity * deltaTime;

    // Vérifier si l'ennemi atteint une extrémité de la patrouille
    if (movingToEnd && position.x >= endPosition.x) {
        movingToEnd = false; // Change de direction
        velocity.x = -std::abs(velocity.x); // Se déplace vers la gauche
    }
    else if (!movingToEnd && position.x <= startPosition.x) {
        movingToEnd = true; // Change de direction
        velocity.x = std::abs(velocity.x); // Se déplace vers la droite
    }
    // Mettre à jour la position du sprite
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