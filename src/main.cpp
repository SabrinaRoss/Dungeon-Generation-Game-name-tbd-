#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include "ui/main_menu.hpp"
#include "core/game_state.hpp"


int main() {
    sf::RenderWindow window;
    sf::Vector2f centerWindow((sf::VideoMode::getDesktopMode().width / 2)-445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    window.create(sf::VideoMode(900, 900), "Dungeon Crawler", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(centerWindow.x, centerWindow.y));
    window.setKeyRepeatEnabled(true);

    //this space instantiate all classes need
    sf::Clock clock;
    float delta_time {0.0};
    sf::Font font;
    
    std::filesystem::path font_path = std::filesystem::current_path() / "assets" / "fonts" / "DejaVuSansMono-Oblique.ttf";
    std::cout << font_path << std::endl;
    if (!font.loadFromFile(font_path)) {
        std::cerr << "Oopsie Error Loading Font!" << std::endl;
        return -1;
    }

    // Textbox textbox1(15, sf::Color::White, false);
    // textbox1.setFont(font);
    // textbox1.setPosition({100,100});
    // textbox1.setLimit(true, 10);
    
    GameState game_state = GameState::START;
    MainMenu main_menu(window, font);
    
    while (window.isOpen()) {
        sf::Event event;
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) textbox1.setSelected(true);
        // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) textbox1.setSelected(false);

        //move this to the main_menu screen with a referance to window
        window.clear();
        switch (game_state) {
        case GameState::START:
            main_menu.eventChecking(event, window, game_state);
            break;
        case GameState::PLAYING:
            break;
        }
        //textbox1.drawTo(window);
        window.display();
    }
    return 0;
}
