// This code took lots of inspiration from this video: https://www.youtube.com/watch?v=T31MoLJws4U
#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
    Button() { }
    Button(std::string t, sf::Vector2f size, int cz, sf::Color bg_col, sf::Color txt_col) {
        text.setString(t);
        text.setFillColor(txt_col);
        text.setCharacterSize(cz);
        button.setSize(size);
        button.setFillColor(bg_col);
    }
    void setFont(sf::Font &font) {text.setFont(font);}
    void setBackColour(sf::Color colour) {button.setFillColor(colour);}
    void setTextColour(sf::Color colour) {button.setFillColor(colour);}
    void setPosition(sf::Vector2f pos) {
        button.setPosition(pos);
        float x_pos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2) -5;
        float y_pos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2) -5;
        text.setPosition({x_pos, y_pos});
    }
    void drawTo(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }
    bool isMouseOver(sf::RenderWindow &window) {
        float mx = sf::Mouse::getPosition(window).x;
        float my = sf::Mouse::getPosition(window).y;
        if (button.getGlobalBounds().contains(mx, my)) return true;
        else return false;
    }
private:
    sf::RectangleShape button;
    sf::Text text;
};