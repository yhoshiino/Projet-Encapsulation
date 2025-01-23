#include "Map.h"

Map::Map(const string& filename) {
	if (!tileset.loadFromFile("tiledungeon.png")) {
		cout << "Introuvable";
	}
	loadMap(filename);
}

Map::~Map() {
	cout << "Map détruite." << std::endl;
}


void Map::draw(sf::RenderWindow& window) {
	for (int i = 0; i < map.size() ; i++) {
		for (int j = 0; j < map[0].size(); j++) {
			cout << map[i][j];
			if (map[i][j] == 'A') {
				sprite.setTexture(tileset);
				sprite.setTextureRect(IntRect(18, 50, 16, 16));
				sprite.setPosition(j * 16, i * 16);
				window.draw(sprite);
				window.display();
			}
		}
	}
}

void Map::loadMap(std::string filename) {
	std::ifstream file(filename);
	file.open(filename);
	if (!file.is_open()) {
		cout << "Impossible d'ouvrir le fichier" << std::endl;
	}
	else {
		std::string line;
		//for (int i = 0; i <= 20; i++) {
		//	map.push_back(line);
		//	cout << line << endl;
		//}
		while (std::getline(file, line)) {
			map.push_back(line);
			std::cout << line << std::endl; // Afficher chaque ligne du fichier
		}
	}
	file.close();
}

