#include "EntityManager.h"
#include <iostream> // Pour des messages de debug, si n�cessaire

// Initialisation de l'instance unique
EntityManager* EntityManager::instance = nullptr;

// M�thode pour obtenir l'instance unique
EntityManager* EntityManager::getInstance() {
    if (instance == nullptr) {
        instance = new EntityManager();
    }
    return instance;
}

// Cr�e un joueur et l'ajoute � la liste des joueurs et des entit�s
void EntityManager::createPlayers(const Texture& texture, const Vector2f& startPosition, float initialSpeed) {
    auto player = make_shared<Player>(texture, startPosition, initialSpeed);
    Players.push_back(player);
    entities.push_back(player);
    cout << "Player cr�� et ajout�.\n";
}

// Cr�e un ennemi et l'ajoute � la liste des ennemis et des entit�s
void EntityManager::createEnemies(const Texture& texture, const Vector2f& startPosition, float initialSpeed) {
    auto enemy = make_shared<Enemy>(texture, startPosition, initialSpeed);
    Enemies.push_back(enemy);
    entities.push_back(enemy);
    cout << "Enemy cr�� et ajout�.\n";
}

 //Cr�e une potion et l'ajoute � la liste des objets et des entit�s
void EntityManager::createPotions(const Texture& texture, const Vector2f& spawnPoint) {
    auto potion = make_shared<Potion>(texture, spawnPoint); // Adaptez si Potion est d�riv�e de Object
    Objects.push_back(potion);
    entities.push_back(potion);
    cout << "Potion cr��e et ajout�e.\n";
}

// Cr�e un chaser et l'ajoute � la liste des chasers et des entit�s
void EntityManager::createChasers(const Texture& texture, const Vector2f& SpawnPosition, float speed) {
    auto chaser = make_shared<Chaser>(texture, SpawnPosition, speed);
    Enemies.push_back(chaser);
    Chasers.push_back(chaser);
    entities.push_back(chaser);
    cout << "Chaser cr�� et ajout�.\n";
}

// Cr�e un patroller et l'ajoute � la liste des patrollers et des entit�s
void EntityManager::createPatrollers(const Texture& texture, const Vector2f& SpawnPosition, float speed) {
    auto patroller = make_shared<Patrolling>(texture, SpawnPosition, speed);
    Enemies.push_back(patroller);
    entities.push_back(patroller);
    cout << "Patroller cr�� et ajout�.\n";
}

// Met � jour toutes les entit�s
void EntityManager::update(float deltaTime) {
    for (auto chaser : Chasers)
    {
        chaser->updateDirection(Players[0]);
    }

    for (auto& entity : entities) {
        entity->update(deltaTime);
    }
    cout << "Toutes les entit�s ont �t� mises � jour.\n";
}

// Dessine toutes les entit�s
void EntityManager::draw(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->draw(window);
    }
    cout << "Toutes les entit�s ont �t� dessin�es.\n";
}

void EntityManager::collisions() {
    for (auto& enemy : Enemies) {
        for (auto player = Players.begin(); player != Players.end(); ++player) {
            if (enemy->getSprite().getGlobalBounds().intersects((*player)->getSprite().getGlobalBounds())) {
                std::cout << "Collision d�tect�e, le joueur est supprim� !" << std::endl;

                Players.erase(player);


            }
        }
    }
}

