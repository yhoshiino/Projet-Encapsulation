#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"



class Enemy : public Entity {
protected:
	Vector2f position; 
	Vector2f velocity; 
	float speed; 
public:
	Enemy(const Texture& texture, const Vector2f& startPosition, float initialSpeed);


	void update(float deltaTime) override;


	void draw(RenderWindow& window) const override;

	const Vector2f& getVelocity() const;
	const Vector2f& getPosition() const;

	void setPosition(const Vector2f& newPosition);
	void setVelocity(const Vector2f& newVelocity);
};


#endif