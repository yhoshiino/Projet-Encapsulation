#pragma once
#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
#include <fstream>
#include <string>

class Map {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	Texture tileset;
	vector<string> map;
public:
	Map(const string& filename);
	~Map();

	void draw(sf::RenderWindow& window);
	void loadMap(std::string path);

	vector<string>& getMap();
};




#endif // !MAP_H
