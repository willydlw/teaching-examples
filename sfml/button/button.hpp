#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>


class Button : public sf::Drawable
{
    public:

    Button(std::string buttonText, sf::Vector2f buttonSize, sf::Vector2f buttonPosition, sf::Font& font);

    void update(sf::Event& event, const sf::Vector2i& mousePosition);
    
    private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void updateTextPosition(void);

    private:

    sf::RectangleShape m_button;
    sf::Vector2f m_position;

    sf::Font m_font;
    sf::Text m_text;

    std::string m_buttonName;
};



#endif 