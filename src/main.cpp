#include <SFML/Graphics.hpp>
#include <iostream>
#include "ui/textbox.hpp"

int main() {
    sf::RenderWindow w;
    sf::Vector2f centerWindow((sf::VideoMode::getDesktopMode().width / 2)-445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    w.create(sf::VideoMode(800, 600), "Dungeon Crawler", sf::Style::Titlebar | sf::Style::Close);
    w.setPosition(sf::Vector2i(centerWindow.x, centerWindow.y));
    w.setKeyRepeatEnabled(true);

    //this space instantiate all classes need
    sf::Clock clock;
    float delta_time {0.0};
    Textbox textbox1(15, sf::Color::White, true);
   
    while (w.isOpen()) {
        sf::Event event;
        while (w.pollEvent(event)) {
            switch(event.type) {

                case sf::Event::Closed:
                    w.close();
                    break;
            }
        }
    }
    w.clear();
    textbox1.drawTwo(w);
    w.display();
}
