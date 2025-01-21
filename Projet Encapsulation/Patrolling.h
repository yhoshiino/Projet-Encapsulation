#ifndef PATROLLING_H
#define PATROLLING_H

#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Patrolling : public Enemy {
private:
private:
    Vector2f startPosition;  
    Vector2f endPosition;   
    Vector2f velocity;      
    bool movingToEnd;        

public:
    // Constructeur
    Patrolling(const Texture& texture, const Vector2f& SpawnPosition, float speed);

    // Méthodes
    void update(float deltaTime) override; // Mise à jour de la position et de la direction
    void draw(RenderWindow& window) override; // Affichage de l'ennemi

    void collisions(Player& player);
};

#endif // PATROLLING_H
