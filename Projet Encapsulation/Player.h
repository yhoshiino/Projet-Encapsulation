#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Player : public Entity {
private:
    Vector2f position; // Position actuelle du joueur
    Vector2f velocity; // Vitesse actuelle du joueur
    float speed; // Vitesse de déplacement

public:
    Player()
        : position(0.f, 0.f), velocity(0.f, 0.f), speed(0.f), Entity() {
        // Ce constructeur initialise les valeurs par défaut
    }
    Player(const Texture& texture, const Vector2f& startPosition, float initialSpeed);

    ~Player();
    void update(float deltaTime) override;


    void draw(RenderWindow& window) override;

    const Vector2f& getVelocity() const;
    const Vector2f& getPosition() const;

    void setPosition(const Vector2f& newPosition);
    void setVelocity(const Vector2f& newVelocity);

    void handleInput();

    void boost();
};

#endif // PLAYER_H




