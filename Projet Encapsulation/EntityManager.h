#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>

#include "Entity.h" // Assurez-vous d'inclure les entit�s g�r�es
#include "Chaser.h"
#include "Potion.h"
#include "Key.h"
#include "Enemy.h"
#include "Patrolling.h"
#include "Player.h"
class EntityManager {
private:
    static EntityManager* instance; // Instance unique
    vector<shared_ptr<Entity>> entities; // Liste des entit�s g�r�es
    vector<shared_ptr<Chaser>> Chasers;
    vector<shared_ptr<Potion>> Potions;
	vector<shared_ptr<Key>> Keys;
    vector<shared_ptr<Enemy>> Enemies;
    vector<shared_ptr<Patrolling>> Patrollers;

    // Constructeur priv� pour emp�cher la cr�ation directe
    EntityManager() = default;

public:
    vector<shared_ptr<Player>> Players;
    // Supprime les constructeurs de copie et d'affectation
    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    // M�thode pour obtenir l'instance unique
    static EntityManager* getInstance();


    void createPlayers(const Texture& texture, const Vector2f& startPosition, float initialSpeed);
    void createEnemies(const Texture& texture, const Vector2f& startPosition, float initialSpeed);
    void createPotions(const Texture& texture, const Vector2f& spawnPoint);
	void createKeys(const Texture& texture, const Vector2f& spawnPoint);
    void createChasers(const Texture& texture, const Vector2f& SpawnPosition, float speed);
    void createPatrollers(const Texture& texture, const Vector2f& SpawnPosition, float speed);

    void collisions();

    // Met � jour toutes les entit�s
    void update(float deltaTime);

    // Dessine toutes les entit�s
    void draw(sf::RenderWindow& window);

    // Destructeur
    ~EntityManager() = default;
};

#endif // !ENTITYMANAGER_H
