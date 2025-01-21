#pragma once
#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "Player.h" 

class Interactable {
public:
    virtual void interact(Player& player) = 0;

    virtual ~Interactable() = default;
};

#endif // INTERACTABLE_H
