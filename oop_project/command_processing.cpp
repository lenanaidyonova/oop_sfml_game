#include "command_processing.h"

CommandProcessing::CommandProcessing(DrawPlayer* drawPlayer) : drawPlayer(drawPlayer) {
    defaultCommands = { {DrawPlayer::RIGHT, Keyboard::D}, {DrawPlayer::LEFT, Keyboard::A}, {DrawPlayer::UP, Keyboard::W}, {DrawPlayer::DOWN, Keyboard::S} };
    this->file.open("default.txt");
}

void CommandProcessing::fillDefaultCommands() {
    std::vector<int> cmds;
    std::vector<int> keys;
    bool flag = true;
    std::string cmd;
    std::string key;
    while (std::getline(file, cmd) && std::getline(file, key)) {
        for (int i = 0; i < cmds.size(); i++) {
            if (cmds[i] == std::stoi(cmd) || keys[i] == std::stoi(key)) {
                commands = defaultCommands;
                flag = false;
                break;
            }
        }
        if (std::stoi(cmd) < 0 || std::stoi(cmd) > SIZE_DIRS || std::stoi(key) < 0 || std::stoi(cmd) > SIZE_KEYBOARD) {
            commands = defaultCommands;
            break;
        }
        if (!flag) break;
        setCommand(static_cast<DrawPlayer::DIRS>(std::stoi(cmd)), static_cast<Keyboard::Key>(std::stoi(key)));
    }
    if (cmd.size() != SIZE_DIRS) {
        commands = defaultCommands;
    }
}

CommandProcessing::~CommandProcessing() {
    this->file.close();
}

void CommandProcessing::setCommand(DrawPlayer::DIRS cmd, Keyboard::Key key) {
    commands[cmd] = key;
}

std::map <DrawPlayer::DIRS, Keyboard::Key> CommandProcessing::getCommands() {
    return commands;
}

void CommandProcessing::callRender(DrawPlayer::DIRS dir) {
    drawPlayer->render(dir);
}

