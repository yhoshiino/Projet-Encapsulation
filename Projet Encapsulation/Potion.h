#ifndef POTION_H
#define POTION_H

#include "Interface.h"
#include "Object.h"
using namespace sf;

class Potion : public Object, public Interactable{
private:
    Vector2f position;

public:

    Potion(const Texture& texture, const Vector2f& spawnPoint);
    ~Potion();
    void interact(Player& player) override;

    void update(float deltaTime) override;
    
    void draw(RenderWindow& window) override;
};

#endif // POTION_H
