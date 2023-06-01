#include "scoreboard.h"


Text ScoreBoard::scoreBoard(Text text, int xp, int health, int key){
    std::ostringstream playerXP, playerKey, playerHealth;
    text.setFillColor(Color::Blue);
    playerXP << xp;
    playerKey << key;
    playerHealth << health;
    text.setString("xp: " + playerXP.str() + "\nhealth: " + playerHealth.str() + "\nkey: " + playerKey.str());
    text.setPosition(0,0);
    return text;
}

Text ScoreBoard::finishBoard(Text text, int health, bool win){
    std::ostringstream playerHealth;
    text.setFillColor(Color::Blue);
    playerHealth << health;
    if (win) {
        text.setString("Congrates!\nYou're WINNER\nhealth: " + playerHealth.str());
    }
    else {
        text.setString("Oh noo!\nYou LOSE!\nhealth: " + playerHealth.str());
    }
    text.setPosition(230,160);
    return text;
    
}
