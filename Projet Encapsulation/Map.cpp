#include "Map.h"

Map::Map(const string& filename) {
    if (!tileset.loadFromFile("tiledungeon.png")) {
        cout << "Introuvable";
    }
    loadMap(filename);
    sprite.setTexture(tileset);
    sprite.setScale(3.f, 3.f);

}

Map::~Map() {
    cout << "Map détruite." << std::endl;
}


void Map::draw(sf::RenderWindow& window) {
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            char tile = map[i][j];
            sprite.setTexture(tileset);

            if (tile == 'F') { // Sol ou zone vide
                sprite.setTextureRect(sf::IntRect(18, 35, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'U') { // Bord haut
                sprite.setTextureRect(sf::IntRect(18, 18, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'L') { // Bord gauche
                sprite.setTextureRect(sf::IntRect(1, 35, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'R') { // Bord droit
                sprite.setTextureRect(sf::IntRect(35, 35, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'D') { // Bord bas
                sprite.setTextureRect(sf::IntRect(18, 52, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'W') {
                sprite.setTextureRect(sf::IntRect(69, 1, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'Z') { // Angle en haut à droite
                sprite.setTextureRect(sf::IntRect(35, 18, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'A') { // Angle en haut à gauche
                sprite.setTextureRect(sf::IntRect(1, 18, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'Q') {
                sprite.setTextureRect(sf::IntRect(1, 52, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'G') {
                sprite.setTextureRect(sf::IntRect(69, 52, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'H') {
                sprite.setTextureRect(sf::IntRect(52, 103, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'E') {
                sprite.setTextureRect(sf::IntRect(52, 69, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'h') {
                sprite.setTextureRect(sf::IntRect(69, 103, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'K') {
                sprite.setTextureRect(sf::IntRect(86, 35, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'k') {
                sprite.setTextureRect(sf::IntRect(86, 69, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'C') {
                sprite.setTextureRect(sf::IntRect(52, 35, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'c') {
                sprite.setTextureRect(sf::IntRect(35, 52, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'X') {
                sprite.setTextureRect(sf::IntRect(86, 52, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'x') {
                sprite.setTextureRect(sf::IntRect(52, 52, 16, 16));
				sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'S') {
                sprite.setTextureRect(sf::IntRect(52, 120, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 's') {
                sprite.setTextureRect(sf::IntRect(69, 120, 16, 16));
				sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'Y') {
                sprite.setTextureRect(sf::IntRect(52, 86, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            else if (tile == 'y') {
                sprite.setTextureRect(sf::IntRect(86, 86, 16, 16));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
			else if (tile == 'd') {
                sprite.setTextureRect(sf::IntRect(52, 103, 16, 16));
                sprite.setPosition(static_cast<float>((j+1) * 16 * 3), static_cast<float>(i * 16 * 3));
                window.draw(sprite);
                sprite.setTextureRect(sf::IntRect(69, 103, 16, 16));
                sprite.setPosition(static_cast<float>((j+2) * 16 * 3), static_cast<float>(i * 16 * 3));
                window.draw(sprite);

                sprite.setTextureRect(sf::IntRect(137, 137, 64, 32));
                sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>((i - 1) * 16 * 3));
                j += 3;
			}
			else if (tile == 'P') {
				sprite.setTextureRect(sf::IntRect(340, 1, 32, 16));
				sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
                j++;
			}
            else if (tile == 'f') {
				sprite.setTextureRect(sf::IntRect(1, 1, 16, 16));
				sprite.setPosition(static_cast<float>(j * 16 * 3), static_cast<float>(i * 16 * 3));
            }
            
            window.draw(sprite);
        }
    }
}

vector<string>& Map::getMap() {
	return map;
}

void Map::loadMap(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        cout << "Impossible d'ouvrir le fichier" << std::endl;
        return;
    }
    map.clear(); // Nettoyer la carte actuelle
    string line;
    while (getline(file, line)) {
        map.push_back(line); // Ajouter chaque ligne au vecteur map
    }
    file.close();
}

