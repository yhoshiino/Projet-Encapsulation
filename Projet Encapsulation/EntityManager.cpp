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
    Potions.push_back(potion);
    entities.push_back(potion);
    cout << "Potion créée et ajoutée.\n";
}

void EntityManager::createKeys(const Texture& texture, const Vector2f& spawnPoint) {
	auto key = make_shared<Key>(texture, spawnPoint); // Adaptez si Potion est dérivée de Object
	Keys.push_back(key);
	entities.push_back(key);
	cout << "Clé créée et ajoutée.\n";
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
}

// Dessine toutes les entités
void EntityManager::draw(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->draw(window);
    }
}

void EntityManager::collisions() {
    for (auto& enemy : Enemies) {
        for (auto player = Players.begin(); player != Players.end(); ++player) {
            if (enemy->getSprite().getGlobalBounds().intersects((*player)->getSprite().getGlobalBounds())) {

                Players.erase(player);
            }
            
        }
    }
    for (auto potion : Potions) {
        if (potion->getSprite().getGlobalBounds().intersects(Players[0]->getSprite().getGlobalBounds())) {
			potion->interact(*Players[0]);
            Potions.erase(remove(Potions.begin(), Potions.end(), potion), Potions.end());
            entities.erase(remove(entities.begin(), entities.end(), potion), entities.end());
        }
    }
    for (auto key : Keys) {
        if (key->getSprite().getGlobalBounds().intersects(Players[0]->getSprite().getGlobalBounds())) {
			key->interact(*Players[0]);
			Keys.erase(remove(Keys.begin(), Keys.end(), key), Keys.end());
			entities.erase(remove(entities.begin(), entities.end(), key), entities.end());
        }
    }

}

