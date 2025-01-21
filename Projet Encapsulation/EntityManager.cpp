#include "EntityManager.h"
#include <iostream> // Pour des messages de debug, si nécessaire

// Initialisation de l'instance unique
EntityManager* EntityManager::instance = nullptr;

// Méthode pour obtenir l'instance unique
EntityManager* EntityManager::getInstance() {
    if (instance == nullptr) {
        instance = new EntityManager();
    }
    return instance;
}

// Crée un joueur et l'ajoute à la liste des joueurs et des entités
void EntityManager::createPlayers(const Texture& texture, const Vector2f& startPosition, float initialSpeed) {
    auto player = make_shared<Player>(texture, startPosition, initialSpeed);
    Players.push_back(player);
    entities.push_back(player);
    cout << "Player créé et ajouté.\n";
}

// Crée un ennemi et l'ajoute à la liste des ennemis et des entités
void EntityManager::createEnemies(const Texture& texture, const Vector2f& startPosition, float initialSpeed) {
    auto enemy = make_shared<Enemy>(texture, startPosition, initialSpeed);
    Enemies.push_back(enemy);
    entities.push_back(enemy);
    cout << "Enemy créé et ajouté.\n";
}

 //Crée une potion et l'ajoute à la liste des objets et des entités
void EntityManager::createPotions(const Texture& texture, const Vector2f& spawnPoint) {
    auto potion = make_shared<Potion>(texture, spawnPoint); // Adaptez si Potion est dérivée de Object
    Objects.push_back(potion);
    entities.push_back(potion);
    cout << "Potion créée et ajoutée.\n";
}

// Crée un chaser et l'ajoute à la liste des chasers et des entités
void EntityManager::createChasers(const Texture& texture, const Vector2f& SpawnPosition, float speed) {
    auto chaser = make_shared<Chaser>(texture, SpawnPosition, speed);
    Enemies.push_back(chaser);
    Chasers.push_back(chaser);
    entities.push_back(chaser);
    cout << "Chaser créé et ajouté.\n";
}

// Crée un patroller et l'ajoute à la liste des patrollers et des entités
void EntityManager::createPatrollers(const Texture& texture, const Vector2f& SpawnPosition, float speed) {
    auto patroller = make_shared<Patrolling>(texture, SpawnPosition, speed);
    Enemies.push_back(patroller);
    entities.push_back(patroller);
    cout << "Patroller créé et ajouté.\n";
}

// Met à jour toutes les entités
void EntityManager::update(float deltaTime) {
    for (auto chaser : Chasers)
    {
        chaser->updateDirection(Players[0]);
    }

    for (auto& entity : entities) {
        entity->update(deltaTime);
    }
    cout << "Toutes les entités ont été mises à jour.\n";
}

// Dessine toutes les entités
void EntityManager::draw(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->draw(window);
    }
    cout << "Toutes les entités ont été dessinées.\n";
}

void EntityManager::collisions() {
    for (auto& enemy : Enemies) {
        for (auto player = Players.begin(); player != Players.end(); ++player) {
            if (enemy->getSprite().getGlobalBounds().intersects((*player)->getSprite().getGlobalBounds())) {
                std::cout << "Collision détectée, le joueur est supprimé !" << std::endl;

                Players.erase(player);


            }
        }
    }
}

