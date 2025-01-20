#include "Patrolling.h"

Patrolling::Patrolling(const Texture& texture, const Vector2f& SpawnPosition, float speed)
    : Enemy(texture, SpawnPosition, speed),
    startPosition(SpawnPosition), // Position initiale
    endPosition(SpawnPosition.x + 200.f, SpawnPosition.y), // Exemple de position finale
    movingToEnd(true) // Commence par aller vers la position finale
{
    // Initialiser la position et la vitesse
    sprite.setTexture(texture);
    sprite.setPosition(startPosition);
    velocity = Vector2f(speed, 0.f); // Se d�place initialement vers la droite
}

void Patrolling::update(float deltaTime)
{
    // Mise � jour de la position en fonction de la vitesse
    position += velocity * deltaTime;

    // V�rifier si l'ennemi atteint une extr�mit� de la patrouille
    if (movingToEnd && position.x >= endPosition.x) {
        movingToEnd = false; // Change de direction
        velocity.x = -std::abs(velocity.x); // Inverse la direction horizontale
    }
    else if (!movingToEnd && position.x <= startPosition.x) {
        movingToEnd = true; // Change de direction
        velocity.x = std::abs(velocity.x); // Inverse la direction horizontale
    }

    // Mettre � jour la position du sprite
    sprite.setPosition(position);
}

void Patrolling::draw(RenderWindow& window) const
{
    window.draw(sprite);
}
