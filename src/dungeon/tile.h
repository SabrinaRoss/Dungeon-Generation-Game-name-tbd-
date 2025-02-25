#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>

enum TileType {
    GROUND,
    WALL,
    MINESWEEPER,
    VOID,
};

const int TILE_SIZE { 8 };

class Tile {
public:
    Tile(int x, int y, TileType type = TileType::VOID);
    int getX() const;
    int getY() const;
    TileType getType() const;
    bool isWalkable() const;
    bool isVisible() const;
    bool isExplored() const;
    void setSprite() const;
    void draw_to(sf::RenderWindow& window);
private:
    int x;
    int y;
    TileType tile_type;
    bool walkable;
    bool visible; // is the tile showing up
    bool expored; 
    sf::Sprite sprite;
}

#endif