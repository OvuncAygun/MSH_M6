#include "LightBlinkAction.h"
#include "SecurityManager.h"
#include <iostream>
#include "sleep.h"

void LightBlinkAction::handle(SecurityManager* mgr) {
    if (!mgr) return;
    for (int i = 0; i < 3; ++i) {
        if (checkInterruption(mgr)) {
            std::cout << "[LIGHT] Blink sequence interrupted." << std::endl;
            return;
        }

        std::cout << "[LIGHT] Blink" << std::endl;
        Sleep(1000);
    }
    handleNext(mgr);
}

