#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pet.hpp"
#include "Information.hpp"
#include <chrono>

std::string timePointToString(const std::chrono::system_clock::time_point& timePoint) {
    auto duration = timePoint.time_since_epoch();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    return std::to_string(seconds.count());
}

int main(){
    int sleep = 100;
    int hunger = 100;
    int hygiene = 100;
    int leisure = 100;
    sf::Clock clock;
    sf::Clock sleepClock;
    int count = 0;
    // картинка потребностей
    sf::Texture textureOfSleep;
    sf::Sprite Sleep;
    textureOfSleep.loadFromFile("content/Sleep.png");
    Sleep.setTexture(textureOfSleep);
    Sleep.setTextureRect(sf::IntRect(0, 0, 126, 124));
    Sleep.setPosition(4, 580);
    //
    sf::Texture textureOfHunger;
    sf::Sprite Hunger;
    textureOfHunger.loadFromFile("content/Hunger.png");
    Hunger.setTexture(textureOfHunger);
    Hunger.setTextureRect(sf::IntRect(0, 0, 126, 124));
    Hunger.setPosition(139, 580);
    //
    sf::Texture textureOfHygiene;
    sf::Sprite Hygiene;
    textureOfHygiene.loadFromFile("content/Hygiene.png");
    Hygiene.setTexture(textureOfHygiene);
    Hygiene.setTextureRect(sf::IntRect(0, 0, 126, 124));
    Hygiene.setPosition(274, 580);
    //
    sf::Texture textureOfLeisure;
    sf::Sprite Leisure;
    textureOfLeisure.loadFromFile("content/Leisure.png");
    Leisure.setTexture(textureOfLeisure);
    Leisure.setTextureRect(sf::IntRect(0, 0, 126, 124));
    Leisure.setPosition(409, 580);

    bool flagTxt = false;

    std::string line;
    std::ifstream in("content/TamaTama.txt", std::ios::app);
    std::ofstream out("content/TamaTama.txt", std::ios::app);
    std::string Line1;
    if (in.is_open()) {
        std::getline(in, line);
        if (! line.empty()) {
            std::cout << "it`s okey" << std::endl;
            flagTxt = true;
        }
        else {
            if (out.is_open()) {
                std::cout << "Write Tama`s name:" << std::endl;
                std::cin >> Line1;
                Write(-1, Line1);
            }
            out.close();
        }
    }
    Line1 = Read(1);
    in.close();
    int Type;
    if (flagTxt != true) {
        std::cout << "Choose: 1.Racoon  2.Goose" << std::endl;
        std::cin >> Type;
        Write(-2, std::to_string(Type));
    }
    std::string TypeStr;
    TypeStr = Read(2);
    Type = std::stoi(TypeStr);
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
    sf::Font NameFont;
    fOnt.loadFromFile("content/ArialRegular.ttf");
    NameFont.loadFromFile("content/WhisperWrite Medium.ttf");
    sf::Text text("", fOnt, 30);
    sf::Text Name("", NameFont, 40);
    Name.setColor(sf::Color(139, 69, 19));
    Name.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::Red);
    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color(255, 248, 220));
    rectangle.setPosition(0, 530);
    int cnt = 0;
    int cntt = 0;

    if (flagTxt == true) {
        std::string sleepStr = std::to_string(sleep);
        std::string hungerStr = std::to_string(hunger);
        std::string hygieneStr = std::to_string(hygiene);
        std::string leisureStr = std::to_string(leisure);
        sleepStr=Read(3);
        hungerStr=Read(4);
        hygieneStr=Read(5);
        leisureStr=Read(6);
        sleep = std::stoi(sleepStr);
        hunger = std::stoi(hungerStr);
        hygiene = std::stoi(hygieneStr);
        leisure = std::stoi(leisureStr);
    }

    if (flagTxt == true) {
        std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
        std::string TimeNow = timePointToString(currentTime);
        std::string TimePast = Read(7);
        int TimeRaz = std::stoi(TimeNow) - std::stoi(TimePast);
        sleep -= (TimeRaz / 1);
        hunger -= (TimeRaz / 1);
        hygiene -= (TimeRaz / 1);
        leisure -= (TimeRaz / 1);
        std::cout << "requirement:" << sleep << std::endl << hunger << std::endl << hygiene << std::endl << leisure << std::endl;
    }

    while (window.isOpen()){
        Name.setString(Line1);
        Name.setPosition(0, 535);
        long time = clock.getElapsedTime().asSeconds();
        if (time % 1 == 0 && count!=time && IsThatDay == true) {
            count = time;
            sleep -= 1;
            hunger -= 1;
            hygiene -= 1;
            leisure -= 1;
            //std::cout << "requirement:" << sleep << std::endl; //<< hunger << std::endl << hygiene << std::endl << leisure << std::endl;
        }
        if (sleep <= 0 && hunger <= 0 && hygiene <= 0 && leisure <= 0) {
            text.setString("Tama got offended and left you.");
            text.setPosition(50, 360);
            cnt += 1;
            if(cnt==300){ window.close(); }
        }
        //
        if (sleep < 100 && sleep >= 80) {
            Sleep.setTextureRect(sf::IntRect(126*0, 0, 126, 124));
        }
        if (sleep < 80 && sleep >= 60) {
            Sleep.setTextureRect(sf::IntRect(126*1, 0, 126, 124));
        }
        if (sleep < 60 && sleep >= 40) {
            Sleep.setTextureRect(sf::IntRect(126*2, 0, 126, 124));
        }
        if (sleep < 40 && sleep >= 20) {
            Sleep.setTextureRect(sf::IntRect(126*3, 0, 126, 124));
        }
        if (sleep < 20 ) {
            Sleep.setTextureRect(sf::IntRect(126*4, 0, 126, 124));
        }
        //
        if (hunger < 100 && hunger >= 80) {
            Hunger.setTextureRect(sf::IntRect(126 * 0, 0, 126, 124));
        }
        if (hunger < 80 && hunger >= 60) {
            Hunger.setTextureRect(sf::IntRect(126 * 1, 0, 126, 124));
        }
        if (hunger < 60 && hunger >= 40) {
            Hunger.setTextureRect(sf::IntRect(126 * 2, 0, 126, 124));
        }
        if (hunger < 40 && hunger >= 20) {
            Hunger.setTextureRect(sf::IntRect(126 * 3, 0, 126, 124));
        }
        if (hunger < 20) {
            Hunger.setTextureRect(sf::IntRect(126 * 4, 0, 126, 124));
        }
        //
        if (hygiene < 100 && hygiene >= 80) {
            Hygiene.setTextureRect(sf::IntRect(126 * 0, 0, 126, 124));
        }
        if (hygiene < 80 && hygiene >= 60) {
            Hygiene.setTextureRect(sf::IntRect(126 * 1, 0, 126, 124));
        }
        if (hygiene < 60 && hygiene >= 40) {
            Hygiene.setTextureRect(sf::IntRect(126 * 2, 0, 126, 124));
        }
        if (hygiene < 40 && hygiene >= 20) {
            Hygiene.setTextureRect(sf::IntRect(126 * 3, 0, 126, 124));
        }
        if (hygiene < 20) {
            Hygiene.setTextureRect(sf::IntRect(126 * 4, 0, 126, 124));
        }
        //
        if (leisure < 100 && leisure >= 80) {
            Leisure.setTextureRect(sf::IntRect(126 * 0, 0, 126, 124));
        }
        if (leisure < 80 && leisure >= 60) {
            Leisure.setTextureRect(sf::IntRect(126 * 1, 0, 126, 124));
        }
        if (leisure < 60 && leisure >= 40) {
            Leisure.setTextureRect(sf::IntRect(126 * 2, 0, 126, 124));
        }
        if (leisure < 40 && leisure >= 20) {
            Leisure.setTextureRect(sf::IntRect(126 * 3, 0, 126, 124));
        }
        if (leisure < 20) {
            Leisure.setTextureRect(sf::IntRect(126 * 4, 0, 126, 124));
        }
        //

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
            // мини-игра. начало
            if ((event.type == sf::Event::MouseButtonPressed) && frame == 3) {
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
                                flagGame = true;
                                while (window.pollEvent(event))
                                {
                                    if (event.type == sf::Event::Closed) {
                                        window.close();
                                        flagGame = false;
                                    }
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
            // мини-игра.конец

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
                        else { 
                            room.setTextureRect(sf::IntRect(0, 0, 540, 720));
                            IsThatDay = true;
                        }
                    }
                }
            }
        }
        if (IsThatDay == false) {
            long sleepTime = sleepClock.getElapsedTime().asSeconds();
            if (sleepTime % 1 == 0 && cntt != sleepTime) {
                sleep += 2;
                cntt = sleepTime;
                if (sleep > 100) {
                    sleep = 100;
                }
                //std::cout << sleep << std::endl;
            }
        }
        if (flagGame == true) {
            long gameTime = sleepClock.getElapsedTime().asSeconds();
            if (gameTime % 1 == 0 && cntt != gameTime) {
                leisure += 2;
                cntt = gameTime;
                if (leisure > 100) {
                    leisure = 100;
                }
                std::cout << leisure << std::endl;
            }
        }
        window.clear();
        window.draw(room);
        if (frame!=2) { window.draw(Pet.TamaSprite());}
        if (frame==2) { window.draw(Pet.BathSprite()); }
        if (frame == 1) { window.draw(Table); }
        window.draw(Sleep);
        window.draw(Hunger);
        window.draw(Hygiene);
        window.draw(Leisure);
        window.draw(rectangle);
        window.draw(Name);
        window.draw(text);
        window.display();
        
    }
    if (flagTxt != true) {
        Write(-3, std::to_string(sleep));
        Write(-4, std::to_string(hunger));
        Write(-5, std::to_string(hygiene));
        Write(-6, std::to_string(leisure));
    }
    else {
        Write(3, std::to_string(sleep));
        Write(4, std::to_string(hunger));
        Write(5, std::to_string(hygiene));
        Write(6, std::to_string(leisure));
    }
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now(); // текущее время в секундах
    if (flagTxt != true) { Write(-7, timePointToString(currentTime)); }
    else { Write(7, timePointToString(currentTime)); }
    
}