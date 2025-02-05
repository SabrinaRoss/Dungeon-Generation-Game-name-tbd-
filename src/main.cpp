#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include "ui/textbox.hpp"
#include "ui/button.hpp"

int main() {
    sf::RenderWindow w;
    sf::Vector2f centerWindow((sf::VideoMode::getDesktopMode().width / 2)-445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    w.create(sf::VideoMode(900, 900), "Dungeon Crawler", sf::Style::Titlebar | sf::Style::Close);
    w.setPosition(sf::Vector2i(centerWindow.x, centerWindow.y));
    w.setKeyRepeatEnabled(true);

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

    Textbox textbox1(15, sf::Color::White, false);
    textbox1.setFont(font);
    textbox1.setPosition({100,100});
    textbox1.setLimit(true, 10);
    
    sf::Vector2u windowSize = w.getSize();
    Button btn1("Click Me", {200, 50}, 10, sf::Color::Green, sf::Color::Black);
    btn1.setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
    btn1.setFont(font);

    while (w.isOpen()) {
        sf::Event event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) textbox1.setSelected(true);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) textbox1.setSelected(false);

        //move this to the main_menu screen with a referance to window
        while (w.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::TextEntered:
                    textbox1.typedOn(event);
                    break;
                case sf::Event::MouseMoved:
                    if (btn1.isMouseOver(w)) btn1.setBackColour(sf::Color::White);
                    else btn1.setBackColour(sf::Color::Green);
                    break;
                case sf::Event::MouseButtonPressed:
                    if (btn1.isMouseOver(w)) std::cout << "placeholder" <<std::endl;
                    break;
                case sf::Event::Closed:
                    w.close();
                    break;
            }
        }
        w.clear();
        textbox1.drawTo(w);
        btn1.drawTo(w);
        w.display();
    }
    return 0;
}
