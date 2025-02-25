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
    if (!t.loadFromFile(filepath) ){ std::cerr << "Error loading the player texture: " << filepath << endl; return; }
    sprite.setTexture(texture);
}
void Player::drawTo(sf::RenderWindow& window) {
    sprite.setPosition(sf::Vector2i(x * TILE_SIZE, y * TILE_SIZE));
    window.draw(sprite);
}