/*
* An SFML application - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* SFML Shapes Tutorials https://www.sfml-dev.org/tutorials/2.5/graphics-shape.php
* SGML Graphics tutorial https://gamefromscratch.com/sfml-c-tutorial-basic-graphics/
*/

#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 

// to do: have the key press events code, window border creation code, and snake code in separate functions in other .cpp/.h files which are called here in main. 

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

            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Key::W:
                        std::cout << "Forward" << std::endl;  // make the snake actually move n shit with slitheryBoi.move [number].f 
                        break;

                    case sf::Keyboard::Key::Up:
                        std::cout << "Forward" << std::endl;
                        break;

                    case sf::Keyboard::Key::A:
                        std::cout << "Left" << std::endl;
                        break;

                    case sf::Keyboard::Key::Left: 
                        std::cout << "Left" << std::endl;
                        break;

                    case sf::Keyboard::Key::S:
                        std::cout << "Back" << std::endl;
                        break;

                    case sf::Keyboard::Key::Down: 
                        std::cout << "Back" << std::endl;
                        break;

                    case sf::Keyboard::Key::D:
                        std::cout << "Right" << std::endl;
                        break;

                    case sf::Keyboard::Key::Right: 
                        std::cout << "Right" << std::endl;
                        break;
                    
                }
            }
        }



#pragma endregion
        
#pragma region Create Window Border
        sf::RectangleShape horiBorder_top(sf::Vector2f(winSize.x, 10)); horiBorder_top.setFillColor(sf::Color(176, 11, 105)); horiBorder_top.setPosition(0, winSize.y-800);
        sf::RectangleShape horiBorder_bottom(sf::Vector2f(winSize.x, 10)); horiBorder_bottom.setFillColor(sf::Color(176, 11, 105)); horiBorder_bottom.setPosition(0, 790); 
        sf::RectangleShape vertBorder_left(sf::Vector2f(winSize.x, 10)); vertBorder_left.setFillColor(sf::Color(176, 11, 105)); vertBorder_left.setPosition(10, 10); vertBorder_left.setRotation(90);
        sf::RectangleShape vertBorder_right(sf::Vector2f(winSize.x, 10)); vertBorder_right.setFillColor(sf::Color(176, 11, 105)); vertBorder_right.setPosition(winSize.x, 10); vertBorder_right.setRotation(90);
#pragma endregion 

#pragma region Snake Create.....
        sf::RectangleShape slitheryBoi(sf::Vector2f(20, 20)); slitheryBoi.setFillColor(sf::Color(1, 79, 2)); slitheryBoi.setPosition(winSize.x / 2, winSize.y / 2);  
        // dividing window size by 2 places our snake in the centre
#pragma endregion 



              
        window.clear(sf::Color(255, 180, 130));                           // Clear graphics buffer
        window.draw(horiBorder_top);
        window.draw(horiBorder_bottom);
        window.draw(vertBorder_left);
        window.draw(vertBorder_right);
        window.draw(slitheryBoi);
        window.display();                                               // Display the graphics from the buffer to the display
        
    }


    return 0;
}