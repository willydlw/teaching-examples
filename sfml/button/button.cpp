#include "button.hpp"

#include <iostream>

Button::Button(std::string buttonText, sf::Vector2f buttonSize, sf::Vector2f buttonPosition, sf::Font& font)
{
    m_button.setSize(buttonSize);
    m_button.setPosition(buttonPosition);
   
    m_buttonName = buttonText;

    m_text.setFont(font);
    m_text.setString(buttonText);
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::Red);

    updateTextPosition();
    
}

void Button::update(sf::Event& event, const sf::Vector2i& mousePosition)
{
    sf::FloatRect gboundsRectangle = m_button.getGlobalBounds();

    bool mouseInBounds =       mousePosition.x >= gboundsRectangle.left        
                            && mousePosition.x <= gboundsRectangle.left + gboundsRectangle.width
                            && mousePosition.y >= gboundsRectangle.top
                            && mousePosition.y <= gboundsRectangle.top + gboundsRectangle.height;

    #if 1
    std::cout   << "Function: " << __FUNCTION__ << ", line: " << __LINE__ << "\n"
                << "mouseInBounds:           " << mouseInBounds << "\n"
                << "mousePosition.x:         " << mousePosition.x << "\n"
                << "gboundsRectangle.left:   " << gboundsRectangle.left << "\n"
                << "gboundsRectangle.width:  " << gboundsRectangle.width << "\n\n"
                << "mousePosition.y:         " << mousePosition.y << "\n"
                << "gboundsRectangle.top:    " << gboundsRectangle.top << "\n"
                << "gboundsRectangle.height: " << gboundsRectangle.height << "\n\n";

    #endif

    if(mouseInBounds)
    {
        if(event.type == sf::Event::MouseMoved)
        {
            m_text.setString("Mouse");
        }
        else if(event.type == sf::Event::MouseButtonPressed)
        {
            switch(event.mouseButton.button)
            {
                case sf::Mouse::Left:
                    m_text.setString("Left Press");
                    break;
                case sf::Mouse::Right:
                    m_text.setString("Right Press");
                    break;
                case sf::Mouse::Middle:
                    m_text.setString("Middle Press");
                    break;
                default:
                    // added to avoid -Wswitch warnings for unhandled button enumerations
                    break;
            }
        }
        else if(event.type == sf::Event::MouseButtonReleased)
        {
            switch(event.mouseButton.button)
            {
                case sf::Mouse::Left:
                    m_text.setString("Left Release");
                    break;
                case sf::Mouse::Right:
                    m_text.setString("Right Release");
                    break;
                case sf::Mouse::Middle:
                    m_text.setString("Middle Release");
                    break;
                default:
                    // added to avoid -Wswitch warnings for unhandled button enumerations
                    break;
            }
        }
        else
        {
            m_text.setString(m_buttonName);
        }

        updateTextPosition();
    }

}

// Centers text in button
void Button::updateTextPosition(void)
{
    sf::Vector2f textPosition;
    sf::FloatRect gboundsRectangle = m_button.getGlobalBounds();
    sf::FloatRect lboundsText = m_text.getLocalBounds();

    #if 0
    std::cout   << "Function: " << __FUNCTION__ << ", line: " << __LINE__ << "\n"
                << "gboundsRectangle.width:  " << gboundsRectangle.width << "\n"
                << "gboundsRectangle.height: " << gboundsRectangle.height << "\n";

    std::cout   << "lboundsText.width:  " << lboundsText.width << "\n"
                << "lboundsText.height: " << lboundsText.height << "\n\n";
    #endif

    // find offsets for text placement
    float offsetX = (gboundsRectangle.width / 2.0f) - (lboundsText.width / 2.0f);
    float offsetY = (gboundsRectangle.height / 2.0f) - (lboundsText.height / 2.0f);

    // center text within shape 
    textPosition.x = gboundsRectangle.left + offsetX;
    textPosition.y = gboundsRectangle.top + offsetY;

    #if 0
    std::cout   << "Function: " << __FUNCTION__ << ", line: " << __LINE__ << "\n"
                << "gboundsRectangle.left: " << gboundsRectangle.left << "\n" 
                << "gboundsRectangle.top:  " << gboundsRectangle.top << "\n"
                << "offsetX:               " << offsetX << "\n" 
                << "offsetY:               " << offsetY << "\n\n";
    #endif

    m_text.setPosition(textPosition);
}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_button, states);
    target.draw(m_text, states);
}