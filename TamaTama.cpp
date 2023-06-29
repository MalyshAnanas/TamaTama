#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pet.hpp"

int main(){
    std::string line;
    std::ifstream in("content/TamaTama.txt", std::ios::app);
    std::ofstream out("content/TamaTama.txt", std::ios::app);
    std::string Line1;
    if (in.is_open()){
        std::getline(in, line);
        if (line != "") {
            std::cout << "it`s okey" << std::endl;
        }
        else {
            if(out.is_open()){
                std::cout << "Write Tama`s name:" << std::endl;
                std::cin >> Line1;
                out << Line1;
            }
            out.close();
        }
    }
    in.close();

    std::cout << "Choose: 1.Racoon  2.Goose" << std::endl; 
    int Type;
    std::cin >> Type;
    Tam Pet(Line1, Type); //Создание объекта Тамы

    std::cout << sf::VideoMode::getDesktopMode().width << " " << sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode(540, 720), "TamaTama");
    window.setFramerateLimit(60);
    sf::Event event;

    sf::Image icon;
    icon.loadFromFile("content/Icon.jpg");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture texture;
    sf::Sprite room;
    texture.loadFromFile("content/Room1.png");
    room.setTexture(texture);
    room.setTextureRect(sf::IntRect(0, 0, 540, 720));
    room.setPosition(0, 0);
    sf::Clock clock;
    float frame = 0;
    bool flagGame = false;
    
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();

            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (frame != 0) {
                    frame -= 1;
                    room.setTextureRect(sf::IntRect(540 * int(frame), 0, 540, 720));
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (frame != 3) {
                    frame += 1;
                    room.setTextureRect(sf::IntRect(540 * int(frame), 0, 540, 720));
                }
            }

            if (frame == 3) { flagGame = true; }
            else { flagGame = false; }

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape) { window.close(); }
                if ((event.key.code == sf::Keyboard::G) && (flagGame==true)) {
                    ////////////
                    sf::Font font;
                    font.loadFromFile("content/ArialRegular.ttf");
                    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game");
                    // Создаем объект игры
                    Game game;
                    game.setPosition(50.f, 50.f);
                    sf::Event event;
                    int move_counter = 0;	// Счетчик случайных ходов для перемешивания головоломки

                    while (window.isOpen())
                    {
                        while (window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed) window.close();
                            if (event.type == sf::Event::KeyPressed)
                            {
                                // Получаем нажатую клавишу - выполняем соответствующее действие
                                if (event.key.code == sf::Keyboard::Escape) window.close();
                                if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
                                if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
                                if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
                                if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);
                                // Новая игра
                                if (event.key.code == sf::Keyboard::F2)
                                {
                                    game.Init();
                                    move_counter = 100;
                                }
                            }
                        }

                        // Если счетчик ходов больше нуля, продолжаем перемешивать головоломку
                        if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

                        // Выполняем необходимые действия по отрисовке
                        window.clear();
                        window.draw(game);
                        window.display();
                    }

                }
            }
        }
        window.clear();
        window.draw(room);
        window.draw(Pet.TamaSprite());
        window.display();
        
    }
    return 0;
}
