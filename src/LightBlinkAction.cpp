#include "LightBlinkAction.h"
#include <iostream>
#include <unistd.h>

void LightBlinkAction::handle(SecurityManager* mgr) {
    for (int i = 0; i < 3; ++i) {
        if (checkInterruption(mgr)) return;
        std::cout << "[LIGHT] Blink" << std::endl;
        sleep(1);
    }
    handleNext(mgr);
}
