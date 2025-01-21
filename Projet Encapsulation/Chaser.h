#pragma once
#ifndef CHASER_H
#define CHASER_H
#include "Enemy.h"
#include "Player.h"
class Chaser : public Enemy {
private:
	int coordY = 0;
	int coordX = 0;
	Player j1;
public:
	Chaser(const Texture& texture, const Vector2f& SpawnPosition, float speed);
	~Chaser();


	void updateDirection(shared_ptr<Player> player);

	void update(float deltaTime) override;


	void draw(RenderWindow& window) override;

	const Vector2f& getVelocity() const;
	const Vector2f& getPosition() const;

	void setPosition(const Vector2f& newPosition);
	void setVelocity(const Vector2f& newVelocity);

	void collisions(shared_ptr<Player> player);
};


#endif // !CHASER_H
