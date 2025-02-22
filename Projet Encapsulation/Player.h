#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Map.h"

class Player : public Entity {
protected:
    Vector2f position; // Position actuelle du joueur
    Vector2f velocity; // Vitesse actuelle du joueur
    float speed; // Vitesse de d�placement
    Clock clockSpeed;
	
public:
    Player()
        : position(0.f, 0.f), velocity(0.f, 0.f), speed(0.f), Entity() {
        // Ce constructeur initialise les valeurs par d�faut
    }
    Player(const Texture& texture, const Vector2f& startPosition, float initialSpeed);

    ~Player();
    void update(float deltaTime) override;

    int keyCount = 0;


    void draw(RenderWindow& window) override;

    const Vector2f& getVelocity() const;
    const Vector2f& getPosition() const;

    void setPosition(const Vector2f& newPosition);
    void setVelocity(const Vector2f& newVelocity);

    void handleInput(float deltaTime, vector<string>& map);

    void boost();

    void addKey();

	int getKey();
};

#endif // PLAYER_H




