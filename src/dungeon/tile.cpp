#include "tile.h"

Title::tile(int x, int y, TileType tile_type) 
    : x(x), y(x), tile_type(tile_type), walkable(false), visible(false), expored(false) {
    
    switch (type) {
        case TileType::VOID:
            break; // for safety
        case TileType::GROUND:
            walkable = true;
            break;
        case TileType:::WALL
            break; // for safety
    }

    // get the sprite here

}


int Tile::getX() const { return x };
int Tile::getY() const { return y };
TileType Tile::getType() const { return tile_type }
bool isWalkable() const { return walkable };
bool isVisible() const { return visible };
bool isExplored() const { return expored };

void draw_to(sf::RenderWindow& window) {  }; // add this more later

