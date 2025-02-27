#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>

enum TileType {
    GROUND,
    WALL,
    MINESWEEPER,
    VOID
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
 //   void setSprite(std::filesystem::path& filepath);
    void drawTo(sf::RenderWindow& window);
    TileType tile_type;
private:
    int x;
    int y;
    bool walkable;
    bool visible; // is the tile showing up
    bool explored; 
    sf::Sprite sprite;
};

#endif