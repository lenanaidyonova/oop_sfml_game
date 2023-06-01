#include "controller.h"


void Controller::keyBoardCommands(CommandProcessing* cmdProcessing) {
    DrawPlayer::DIRS pressed;
    for (int i = 0; i < cmdProcessing->getCommands().size(); i++) {
        pressed = static_cast<DrawPlayer::DIRS>(i);
        if (Keyboard::isKeyPressed(cmdProcessing->getCommands()[pressed])) {
            cmdProcessing->callRender(pressed);
            break;
        }
    }
}