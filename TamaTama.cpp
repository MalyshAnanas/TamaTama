#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pet.hpp"

int main(){
    int sleep = 100;
    int hunger = 100;
    int hygiene = 100;
    int leisure = 100;
    sf::Clock clock;
    int count = 0;

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

    sf::RenderWindow window(sf::VideoMode(540, 720), "TamaTama");
    window.setFramerateLimit(60);
    sf::Event event;

    sf::Image icon;
    icon.loadFromFile("content/Icon.jpg");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture texture;
    sf::Sprite room;
    texture.loadFromFile("content/Room.png");
    room.setTexture(texture);
    room.setTextureRect(sf::IntRect(0, 0, 540, 720));
    room.setPosition(0, 0);
    sf::Texture TextureOfTable;
    sf::Sprite Table;
    TextureOfTable.loadFromFile("content/Table.png");
    Table.setTexture(TextureOfTable);
    Table.setTextureRect(sf::IntRect(0, 0, 540, 720));
    Table.setPosition(11, 382);
    float frame = 0;
    bool flagGame = false;
    bool IsThatDay = true;

    sf::Font fOnt;
    fOnt.loadFromFile("content/ArialRegular.ttf");
    sf::Text text("", fOnt, 30);
    text.setColor(sf::Color::Red);
    int cnt = 0;

    while (window.isOpen()){

        long time = clock.getElapsedTime().asSeconds();
        if (time % 1 == 0 && count!=time) {
            count = time;
            sleep -= 1;
            hunger -= 1;
            hygiene -= 1;
            leisure -= 1;
            //std::cout << "requirement:" << sleep << std::endl << hunger << std::endl << hygiene << std::endl << leisure << std::endl;
        }
        if (sleep <= 0 && hunger <= 0 && hygiene <= 0 && leisure <= 0) {
            text.setString("Tama got offended and left you.");
            text.setPosition(50, 360);
            cnt += 1;
            if(cnt==300){ window.close(); }
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 7 && event.mouseButton.x < 99 && event.mouseButton.y>12 && event.mouseButton.y < 101) {
                if (frame != 0) {
                    frame -= 1;
                    room.setTextureRect(sf::IntRect(540 * int(frame), 0, 540, 720));
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 440 && event.mouseButton.x < 532 && event.mouseButton.y>12 && event.mouseButton.y < 101) {
                if (frame != 3) {
                    frame += 1;
                    room.setTextureRect(sf::IntRect(540 * int(frame), 0, 540, 720));
                }
            }
            if (frame == 3) { flagGame = true; }
            else { flagGame = false; }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (frame == 3 && event.mouseButton.x > 0 && event.mouseButton.x < 151 && event.mouseButton.y>360 && event.mouseButton.y < 521) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
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

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (frame == 0 && event.mouseButton.x > 0 && event.mouseButton.x < 126 && event.mouseButton.y>298 && event.mouseButton.y < 497)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (IsThatDay == true)
                        {
                            room.setTextureRect(sf::IntRect(0, 720, 540, 720));
                            IsThatDay = false;
                        }
                        else { room.setTextureRect(sf::IntRect(0, 0, 540, 720)); IsThatDay = true; }
                    }
                }
            }
        }
        window.clear();
        window.draw(room);
        if (frame!=2) { window.draw(Pet.TamaSprite());}
        if (frame==2) { window.draw(Pet.BathSprite()); }
        if (frame == 1) { window.draw(Table); }
        window.draw(text);
        window.display();
        
    }
    return 0;
}