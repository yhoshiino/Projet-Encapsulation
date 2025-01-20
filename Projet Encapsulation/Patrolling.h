#ifndef PATROLLING_H
#define PATROLLING_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Patrolling : public Enemy {
private:
    Vector2f startPosition;  // Point de d�part de la patrouille
    Vector2f endPosition;    // Point de fin de la patrouille
    bool movingToEnd;        // Indique si l'ennemi se d�place vers la position finale

public:
    // Constructeur
    Patrolling(const Texture& texture, const Vector2f& SpawnPosition, float speed);

    // M�thodes
    void update(float deltaTime) override; // Mise � jour de la position et de la direction
    void draw(RenderWindow& window) const override; // Affichage de l'ennemi
};

#endif // PATROLLING_H
