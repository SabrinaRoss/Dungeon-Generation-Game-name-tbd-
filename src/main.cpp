#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon Crawler");

    //this space instantiate all classes need

    sf::Clock clock;
    float delta_time {0.0};
    
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close(); //change this to specific button start game
    
    //window.clear(sf::Color::Black);
        window.display(); 
    }
    return 0;
}
