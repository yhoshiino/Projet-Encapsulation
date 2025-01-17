#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
const int Width = 1440;
const int Height = 1080;
class Entity {
protected:
    Sprite sprite; // Rendu accessible aux classes d�riv�es
public:
    Entity(const Texture& texture);

    const Sprite& getSprite() const; // Doit retourner une r�f�rence constante

    void setTexture(const sf::Texture& texture); 

    virtual void update(float deltaTime) = 0; 
    virtual void draw(RenderWindow& window) const; 

    virtual ~Entity() = default; // Destructeur virtuel
};

#endif // ENTITY_H
