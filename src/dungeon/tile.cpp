#include "tile.h"

Tile::Tile(int x, int y, TileType tile_type) 
    : x(x), y(y), tile_type(tile_type), walkable(false), visible(false), explored(false) {
    
    switch (type) {
        case TileType::VOID:
            break; // for safety
        case TileType::GROUND:
            walkable = true;
            break;
        case TileType::WALL:
            break; // for safety
        case TileType::MINESWEEPER:
            break;
    }

    // get the sprite here

}


int Tile::getX() const { return x };
int Tile::getY() const { return y };
TileType Tile::getType() const { return tile_type };
bool Tile::isWalkable() const { return walkable };
bool Tile::isVisible() const { return visible };
bool Tile::isExplored() const { return explored };
void Tile::setSprite(sf::filesystem::path& filepath) { 
    sf::Texture texture;
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "Error loading the Texture: " << filepath << std::endl;
        return;
    }
    sprite = sf::Sprite(texture);
}
void Tile::drawTo(sf::RenderWindow& window) { 
    sprite.setPosition(sf::Vector2i(x * TILE_SIZE, y * TILE_SIZE));
    window.draw(sprite);
 }; // add this more later

//std::filesystem::current_path() / "assets" / "minesweeper";
