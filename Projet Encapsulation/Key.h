#pragma once
#ifndef KEY_H
#define KEY_H
#include "Object.h"
#include "Interface.h"

class Key : public Object, public Interactable {
private:
	Vector2f position;
public:
	Key(const Texture& texture, const Vector2f& spawnPoint);
	~Key();

	void interact(Player& player) override;

	void update(float deltaTime) override;

	void draw(RenderWindow& window) override;

};

#endif