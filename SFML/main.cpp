/*
* An SFML application - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* SFML Shapes Tutorials https://www.sfml-dev.org/tutorials/2.5/graphics-shape.php
* SGML Graphics tutorial https://gamefromscratch.com/sfml-c-tutorial-basic-graphics/
*/
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 
#include "graphPoints.h"

int main()
{
#pragma region Window Creation
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Snake Gameing", sf::Style::Default, sf::ContextSettings(24));   // render a Window
    window.setVerticalSyncEnabled(true);
    sf::Vector2u winSize = window.getSize();
#pragma endregion
    
    while (window.isOpen())                                             // This is the Windows application loop - infinite loop until closed
    {
#pragma region Check for Exit
        sf::Event event;                                                // Windows is event driven - so check for events
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

#pragma endregion
        
#pragma region Create Window Border
        sf::RectangleShape horizontalborder(sf::Vector2f(winSize.x, 10)); horizontalborder.setFillColor(sf::Color(176, 11, 105)); horizontalborder.setPosition(0, winSize.y-800);
        
#pragma endregion 

        window.clear();                                                 // Clear graphics buffer
        window.draw(horizontalborder);
        window.display();                                               // Display the graphics from the buffer to the display
        
    }


    return 0;
}