#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "Player.h"

class Object : public Entity {
public:

    Object(const Texture& texture);

    void update(float deltaTime) override;
    void draw(RenderWindow& window) override;
 
};

#endif // OBJECT_H
