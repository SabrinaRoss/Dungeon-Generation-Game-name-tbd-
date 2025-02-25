#include "tile.h"

Title::tile(int x, int y, TileType tile_type) 
    : x(x), y(x), tile_type(tile_type), walkable(false), visible(false), expored(false) {
    
    switch (type) {
        case TileType::VOID:
            break; // for safety
        case TileType::GROUND:
            walkable = true;
            break;
        case TileType:::WALL:
            break; // for safety
        case TileType::MINESWEEPER:
            break;
    }

    // get the sprite here

}


int Tile::getX() const { return x };
int Tile::getY() const { return y };
TileType Tile::getType() const { return tile_type }
bool Tile::isWalkable() const { return walkable };
bool Tile::isVisible() const { return visible };
bool Tile::isExplored() const { return expored };
void Tile::setSprite(sf::filesystem::path& filepath) const { 
    sf::Texture texture;
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "Error loading the Texture: " << filepath << std::endl;
        return;
    }
    spirte = sf::Sprite(texture);
}
void Tile::draw_to(sf::RenderWindow& window) { 
    spirte.setPosition(sf::Vector2i(x, y));
    window.draw(sprite);
 }; // add this more later

//std::filesystem::current_path() / "assets" / "minesweeper";
