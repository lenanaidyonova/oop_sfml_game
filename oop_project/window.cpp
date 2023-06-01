#include "window.h"

std::pair<int,int> ProjectWindow::menu() {
    RenderWindow window(sf::VideoMode(640, 480), "Menu");
    Texture menuTexture1; Texture menuTexture2; Texture menuTexture3; Texture menuTexture4;
    menuTexture1.loadFromFile("10.png"); menuTexture2.loadFromFile("20.png"); menuTexture3.loadFromFile("30.png"); menuTexture4.loadFromFile("field.png");
    Sprite menu1(menuTexture1); Sprite menu2(menuTexture2); Sprite menu3(menuTexture3); Sprite menu4(menuTexture4);
    bool isMenu = 1;
    int menuNum = 0;
    std::pair<int, int> sizeField;
    menu1.setPosition(215, 70); menu2.setPosition(210, 170); menu3.setPosition(210, 270);  menu4.setPosition(70, 0);

    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        menu1.setColor(Color::Magenta);
        menu2.setColor(Color::Magenta);
        menu3.setColor(Color::Magenta);
        menu4.setColor(Color::Magenta);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(215, 70, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
        if (IntRect(210, 170, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
        if (IntRect(210, 270, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                isMenu = false;
                sizeField.first = 10;
                sizeField.second = 10;
            }

            if (menuNum == 2) {
                isMenu = false;
                sizeField.first = 20;
                sizeField.second = 20;
            }

            if (menuNum == 3) {
                isMenu = false;
                sizeField.first = 30;
                sizeField.second = 30;
            }
        }
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        window.display();
    }

    return sizeField;
}

void ProjectWindow::finishWindow(Creator* creator){
    RenderWindow window(sf::VideoMode(640, 480), "Ur results");
    Font font;
    font.loadFromFile("Athelas-Regular.ttf");
    Text text("", font, 36);
    bool win = true;
    if (creator->getPlayer()->getKey() < 3) win = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(Color(129, 181, 221));

        window.draw(creator->getScoreBoard()->finishBoard(text, creator->getPlayer()->getHealth(), win));
        window.display();
    }

}

Level* ProjectWindow::levelWindow(){
    RenderWindow window(sf::VideoMode(640, 480), "Menu");
    Texture menuTexture1; Texture menuTexture2; Texture menuTexture3; 
    menuTexture1.loadFromFile("level.png"); menuTexture2.loadFromFile("first.png"); menuTexture3.loadFromFile("second.png");
    Sprite menu1(menuTexture1); Sprite menu2(menuTexture2); Sprite menu3(menuTexture3);
    bool isMenu = 1;
    int menuNum = 0;
    std::pair<int, int> sizeField;
    menu1.setPosition(210, 70); menu2.setPosition(210, 170); menu3.setPosition(210, 270); 

    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        menu1.setColor(Color::Magenta);
        menu2.setColor(Color::Magenta);
        menu3.setColor(Color::Magenta);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(210, 170, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 1; }
        if (IntRect(210, 270, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 2; }
  

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                return new FirstLevel();
            }

            if (menuNum == 2) {
                return  new SecondLevel();
            }

          
        }
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.display();
    }
}


void ProjectWindow::openWindow(Creator* creator){
    RenderWindow window(sf::VideoMode(640, 480), "Game");
    
    Clock clock;
    float currentFrame = 0;
    Font font;
    font.loadFromFile("Athelas-Regular.ttf");
    Text text("", font, 18);
    sf::Event event;

    while (window.isOpen() && creator->getPlayer()->getAlive()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        currentFrame = creator->getDrawPlayer()->getCurrentFrame();
        currentFrame += 0.01 * time;
        if (currentFrame > 4) currentFrame -= 4;
        creator->getDrawPlayer()->setCurrentFrame(currentFrame);
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Escape) {
                for (int i = 0; i < creator->getControls().size(); i++) {
                    creator->getControls().at(i)->controlScan(creator->getCommandProcessing());
                }
            }
        }

        if (creator->getPlayer()->getAlive()) {
            creator->getController()->keyBoardCommands(creator->getCommandProcessing());
        }
        creator->getDrawPlayer()->updatePosition(time, creator->getField(), creator->getLoggerPool());
        creator->getEventManager()->manage(creator->getPlayer(), creator->getField(), creator->getFactory(), creator->getLoggerPool());

        window.clear();

        creator->getDrawField()->setSpriteMap(creator->getField(), window);
        window.draw(creator->getScoreBoard()->scoreBoard(text, creator->getPlayer()->getXP(), creator->getPlayer()->getHealth(), creator->getPlayer()->getKey()));
        window.draw(*creator->getDrawPlayer()->getSpritePlayer());
        window.display();
    }
   
}

std::vector<LogType*> ProjectWindow::logWindow() {
    std::vector<LogType*> logs;
    RenderWindow window(sf::VideoMode(640, 480), "Log");
    Texture menuTexture1; Texture menuTexture2; Texture menuTexture3; Texture menuTexture4;
    menuTexture1.loadFromFile("game log.png"); menuTexture2.loadFromFile("play log.png"); menuTexture3.loadFromFile("error log.png"); menuTexture4.loadFromFile("next.png");
    Sprite menu1(menuTexture1); Sprite menu2(menuTexture2); Sprite menu3(menuTexture3); Sprite menu4(menuTexture4);
    bool isMenu = 1;
    bool isGameLog = 0;
    bool isPlayLog = 0;
    bool isErrorLog = 0;
    int menuNum = 0;
    std::pair<int, int> sizeField;
    menu1.setPosition(210, 70); menu2.setPosition(210, 170); menu3.setPosition(210, 270); menu4.setPosition(210, 370);

    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
     
        menuNum = 0;
        window.clear(Color(129, 181, 221));
        menu4.setColor(Color::Magenta);

        if (IntRect(210, 70, 300, 50).contains(Mouse::getPosition(window)) && isGameLog == false) { menu1.setColor(Color::Blue); menuNum = 1; }
        else if (isGameLog == false)  menu1.setColor(Color::Magenta);
        if (IntRect(210, 170, 300, 50).contains(Mouse::getPosition(window)) && isPlayLog == false) { menu2.setColor(Color::Blue); menuNum = 2; }
        else if (isPlayLog == false)  menu2.setColor(Color::Magenta);
        if (IntRect(210, 270, 300, 50).contains(Mouse::getPosition(window)) && isErrorLog == false) { menu3.setColor(Color::Blue); menuNum = 3; }
        else if (isErrorLog == false)  menu3.setColor(Color::Magenta);
        if (IntRect(210, 370, 300, 50).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Blue); menuNum = 4; }

        if (logs.size() == 3) menuNum = 4;

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                logs.push_back(new GameLog());
                isGameLog = true;
                menu1.setColor(Color::Blue);
            }

            if (menuNum == 2) {
                logs.push_back(new PlayLog());
                isPlayLog = true;
                menu1.setColor(Color::Blue);
            }

            if (menuNum == 3) {
                logs.push_back(new ErrorLog());
                isErrorLog = true;
                menu1.setColor(Color::Blue);
            }

            if (menuNum == 4) {
                isMenu = false;
            }
        }
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        window.display();
    }
    /*
    if (logs.empty()) {
        logs.push_back(new GameLog());
        logs.push_back(new PlayLog());
        logs.push_back(new ErrorLog());
    }*/
    return logs;
}

std::vector<Logger*> ProjectWindow::outLogWindow(){
    std::vector<Logger*> loggers;
    RenderWindow window(sf::VideoMode(640, 480), "Log");
    Texture menuTexture1; Texture menuTexture2; Texture menuTexture3; Texture menuTexture4;
    menuTexture1.loadFromFile("consol.png"); menuTexture2.loadFromFile("file.png"); menuTexture3.loadFromFile("next.png");
    Sprite menu1(menuTexture1); Sprite menu2(menuTexture2); Sprite menu3(menuTexture3);
    bool isMenu = true;
    bool isConsole = false;
    bool isFile = false;
    int menuNum = 0;
    menu1.setPosition(10, 70); menu2.setPosition(10, 170); menu3.setPosition(10, 270); 

    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
     
        menuNum = 0;
        window.clear(Color(129, 181, 221));
        menu3.setColor(Color::Magenta);

        if (IntRect(10, 70, 300, 50).contains(Mouse::getPosition(window)) && isConsole == false) { menu1.setColor(Color::Blue); menuNum = 1; }
        else if (isConsole == false)  menu1.setColor(Color::Magenta);
        if (IntRect(10, 170, 300, 50).contains(Mouse::getPosition(window)) && isFile == false) { menu2.setColor(Color::Blue); menuNum = 2; }
        else if (isFile == false)  menu2.setColor(Color::Magenta);
        if (IntRect(10, 270, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

        if (loggers.size() == 2) menuNum = 3;

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                loggers.push_back(new ConsoleLogger());
                isConsole = true;
                menu1.setColor(Color::Blue);
            }

            if (menuNum == 2) {
                loggers.push_back(new FileLogger());
                isFile = true;
                menu2.setColor(Color::Blue);
            }

            if (menuNum == 3) {
                isMenu = false;
            }
        }
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.display();
    }
    /*
    if (loggers.empty()) {
        loggers.push_back(new ConsoleLogger());
        loggers.push_back(new FileLogger());

    }*/
    return loggers;
}

std::vector<ControlScan*> ProjectWindow::controlScanWindow(WindowCommand* windowCommand) {
    std::vector<ControlScan*> controls;
    RenderWindow window(sf::VideoMode(640, 480), "Controll");
    std::pair<int, int> size;
    Texture levelTexture1, levelTexture3;
    levelTexture1.loadFromFile("gui.png");
    levelTexture3.loadFromFile("next.png");
    Sprite menu1(levelTexture1), menu3(levelTexture3);
    bool isMenu = true;
    bool isConsole = false;
    bool isFile = false;
    int menuNum = 0;
    menu1.setPosition(0, 0);
    menu3.setPosition(0, 100);
    sf::Event event;

    while (isMenu)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(0, 0, 300, 50).contains(Mouse::getPosition(window)) && isConsole == false) { menu1.setColor(Color::Blue); menuNum = 1; }
        else if (isConsole == false)menu1.setColor(Color::Magenta);
        if (IntRect(0, 100, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
        else menu3.setColor(Color::Magenta);

        if (controls.size() == 1) menuNum = 3;

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                controls.push_back(new ControlGUI(windowCommand));
                isConsole = true;
                menu1.setColor(Color::Magenta);
            }
            if (menuNum == 3) {
                isMenu = false;
            }

        }
        window.draw(menu1);
        window.draw(menu3);

        window.display();
    }

    if (controls.empty()) {
        controls.push_back(new ControlGUI(windowCommand));
    }
    
    return controls;
}


