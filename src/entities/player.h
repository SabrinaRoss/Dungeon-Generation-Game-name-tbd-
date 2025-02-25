#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>

const int TILE_SIZE { 8 };

class Player {
public:
    Player(int x = 0, int y = 0, int health = 1); also change the default positions and health later
    int getX() const;
    int getY() const;
    int getHealth() const;
    void move(int gx, int gy);
    void hit(int damage);
    void setSprite(std::filesystem::path& filepath);
    void drawTo(sf::RenderWindow& window);
private:
    int x;
    int y;
    int health;
    sf::Sprite sprite;
}

#endif