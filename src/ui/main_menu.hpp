#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "textbox.hpp"
#include "button.hpp"

class MainMenu {
public:
    MainMenu() { }
    MainMenu(sf::RenderWindow &w, sf::Font &f) {
        font = f;
        setColour(sf::Color::Green);
        createButton("Start Game", {200, 50}, default_colour, w);
        createButton("Quit", {200, 50}, default_colour, w);
    }
    void setColour(sf::Color colour) { default_colour = colour;}
    void eventChecking(sf::Event &event, sf::RenderWindow &window) {
        while (window.pollEvent(event)) {
            switch(event.type) {
            // case sf::Event::TextEntered:
            //     textbox1.typedOn(event);
        //         break;
                case sf::Event::MouseMoved:
                    for (auto &btn: buttons) {
                        if (btn.isMouseOver(window)) btn.setBackColour(sf::Color::White);
                        else btn.setBackColour(default_colour);
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    for (auto &btn: buttons) {
                        if (btn.isMouseOver(window)) std::cout << "placeholder" <<std::endl;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        } for (auto &btn : buttons) btn.drawTo(window);
    }
private:
    sf::Font font;
    std::vector<Button> buttons;
    sf::Color default_colour;

    void createButton(std::string s, const sf::Vector2f &size, sf::Color &colour, sf::RenderWindow &window) {
        sf::Vector2u windowSize = window.getSize();
        Button btn(s, size, 15, colour, sf::Color::Black);
        btn.setPosition({windowSize.x / 2.f - size.x + 80, windowSize.y / 2.f + buttons.size() * 60.f});
        btn.setFont(font);
        buttons.push_back(btn);
    }
};