#include "Potion.h"

// Constructeur
Potion::Potion(const Texture& texture, const Vector2f& spawnPoint)
    : Object(texture), position(spawnPoint) {
    sprite.setPosition(position); // Place le sprite � la position de la potion
}

void Potion::interact(Player& player) {
    if (player.getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds())) {
        player.boost();
        cout << "Le joueur utilise la potion !" << std::endl;
    }
    
}


void Potion::update(float deltaTime) {

}


void Potion::draw(RenderWindow& window) {
    window.draw(sprite);
}
