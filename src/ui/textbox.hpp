// This code took lots of inspiration from this video: https://www.youtube.com/watch?v=T31MoLJws4U
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
// change the defines laster, I do not like defines make like a enum

class Textbox {
public:
    Textbox() { }
    Textbox(int size, sf::Color colour, bool sel) {
        textbox.setCharacterSize(size);
        textbox.setFillColor(colour);
        is_selected = sel;
        if (sel) textbox.setString(" ");
        else textbox.setString("");
    }
    void setFont(sf::Font &font) {textbox.setFont(font);}
    void setPosition(sf::Vector2f pos) {textbox.setPosition(pos);}
    void setLimit(bool tf) {has_limit = tf;}
    void setLimit(bool tf, int lim) {
        has_limit = tf;
        limit = lim - 1;
    }
    void setSelected(bool sel) {
        is_selected = sel;
        if (!sel) {
            std::string t = text.str();
            std::string nt = "";
            size_t i { 0 };
            for (; i < t.length(); i++) nt += t[i];
            text.str("");
        }
    }
    std::string getText() {return text.str();}

    void drawTo(sf::RenderWindow &window) {window.draw(textbox);}
    void typedOn(sf::Event &input) {
        if (is_selected) {
            int ct = input.text.unicode;
            if (ct < 128) {
                if (has_limit) {
                    if (text.str().length() <= limit) inputLogic(ct);
                    else if (text.str().length() > limit && ct == DELETE_KEY) deleteLastChar();
                } else inputLogic(ct);
            }
        }
    }
    //passing input by referance, experienctal change 
private:
    sf::Text textbox;
    std::ostringstream text;
    bool is_selected = false;
    bool has_limit = false;
    int limit;

    void inputLogic(int ct) {
        if (ct != DELETE_KEY && ct != ENTER_KEY && ct != ESCAPE_KEY) text << static_cast<char>(ct);
        else if (ct == DELETE_KEY) if (text.str().length() > 0) {
            deleteLastChar();
        }
        textbox.setString(text.str() + "_");
    }
    void deleteLastChar() {
        std::string t = text.str();
        std::string nt = "";
        int i { 0 };
        for (; i < t.length() - 1; i++) nt += t[i];
        text.str("");
        text << nt;
        textbox.setString(text.str());
    }
};