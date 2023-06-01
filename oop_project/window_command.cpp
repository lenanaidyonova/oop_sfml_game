#include "window_command.h"

std::map<DrawPlayer::DIRS, Keyboard::Key> WindowCommand::controlCommands() {
    RenderWindow window(sf::VideoMode(640, 480), "Ur results");
    std::map<DrawPlayer::DIRS, Keyboard::Key> commands;
    Texture levelTexture1, levelTexture2, levelTexture3, levelTexture4;
    levelTexture1.loadFromFile("left.png");
    levelTexture2.loadFromFile("right.png");
    levelTexture3.loadFromFile("up.png");
    levelTexture4.loadFromFile("down.png");
    Sprite menu1(levelTexture1), menu2(levelTexture2), menu3(levelTexture3), menu4(levelTexture4);
    bool isMenu = true;
    int menuNum = 0;
    std::vector<bool> isCommand = { false, false, false, false };
    /*
    bool isLeft = false;
    bool isRight = false;
    bool isUp = false;
    bool isDown = false;*/
    bool doubleKey = true;
    bool wait = true;
    bool pressed = false;
    std::vector<int> keys;

    menu1.setPosition(0, 0);
    menu2.setPosition(0, 80);
    menu3.setPosition(0, 160);
    menu4.setPosition(0, 240);
    std::vector<Sprite> menu = { menu1, menu2, menu3, menu4 };


    sf::Event event;
    int key;


    while (isMenu) {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                isMenu = false;
            }
            else if (event.type == Event::KeyPressed) {
                key = event.key.code;

                for (int i = 0; i < keys.size(); i++) {
                    if (key == keys.at(i)) {
                        doubleKey = false;
                        break;
                    }
                    doubleKey = true;
                }

                if (pressed && doubleKey) {
                    keys.push_back(key);

                    if (keys.size() == 4) {
                        isMenu = false;
                    }

                    wait = true;

                    commands[static_cast<DrawPlayer::DIRS>(menuNum-1)] = static_cast<Keyboard::Key>(key);

                    menuNum = 0;
                }
            }
        }

        window.clear(Color(129, 181, 221));

        if (wait) {
            if (IntRect(0, 0, 190, 60).contains(Mouse::getPosition(window)) && isCommand.at(DrawPlayer::LEFT) == false) { menu1.setColor(Color::Blue); menuNum = 1; }
            else if (isCommand.at(DrawPlayer::LEFT) == false) menu1.setColor(Color::White);

            if (IntRect(0, 80, 190, 60).contains(Mouse::getPosition(window)) && isCommand.at(DrawPlayer::RIGHT) == false) { menu2.setColor(Color::Blue); menuNum = 2; }
            else if (isCommand.at(DrawPlayer::RIGHT) == false) menu2.setColor(Color::White);

            if (IntRect(0, 160, 190, 60).contains(Mouse::getPosition(window)) && isCommand.at(DrawPlayer::UP) == false) { menu3.setColor(Color::Blue); menuNum = 3; }
            else if (isCommand.at(DrawPlayer::UP) == false) menu3.setColor(Color::White);

            if (IntRect(0, 240, 190, 60).contains(Mouse::getPosition(window)) && isCommand.at(DrawPlayer::DOWN) == false) { menu4.setColor(Color::Blue); menuNum = 4; }
            else if (isCommand.at(DrawPlayer::DOWN) == false) menu4.setColor(Color::White);


            if (Mouse::isButtonPressed(Mouse::Left))
            {   
                menu.at(menuNum-1).setColor(Color::Magenta);
                isCommand.at(menuNum - 1) = true;

                /*
                switch (menuNum) {
                case(1):
                    menu1.setColor(Color::Magenta);		
                    isLeft = true;
                    break;
                case(2):
                    menu2.setColor(Color::Magenta);
                    isRight = true;
                    break;
                case(3):
                    menu3.setColor(Color::Magenta);
                    isUp = true;
                    break;
                case(4):
                    menu4.setColor(Color::Magenta);
                    isDown = true;
                    break;
                }*/

                pressed = true;
                wait = false;
            }
        }

        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);

        window.display();
    }

    return commands;
}