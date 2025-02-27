#include "player.h"

Player::Player(int x, int y, int health)
    : x(x), y(y), health(health) {}

int Player::getX() const { return x; }
int Player::getY() const { return y; }
int Player::getHealth() const { return health; }
void Player::move(int gx, int gy) {
    x += gx;
    y += gy;
    // add some border control later onwards
}
void Player::hit(int damage) {
    health -= damage;
    if (health <= 0) health = 0;

}
void Player::setSprite(std::filesystem::path& filepath) {
    sf::Texture t;
    if (!t.loadFromFile(filepath) ){ std::cerr << "Error loading the player texture: " << filepath << std::endl; return; }
    sprite.setTexture(t);
}
void Player::drawTo(sf::RenderWindow& window) {
    sf::Vector2i pixelPosition(x * TILE_SIZE, y * TILE_SIZE);
    sf::Vector2f floatPosition(static_cast<float>(pixelPosition.x), static_cast<float>(pixelPosition.y));
    sprite.setPosition(floatPosition);
    window.draw(sprite);
}