#include "control_scan.h"

ControlScan::ControlScan() {}


void ControlScan::setControll(CommandProcessing* cmdProcessing) {
    this->file.open("controllKeys.txt");
    std::string cmd;
    std::string key;

    while (std::getline(file, cmd), std::getline(file, key)) {
        cmdProcessing->setCommand(static_cast<DrawPlayer::DIRS>(std::stoi(cmd)), static_cast<Keyboard::Key>(std::stoi(key)));
    }
    this->file.close();
}