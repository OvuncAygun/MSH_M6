#include "LightBlinkAction.h"
#include <iostream>
#include "sleep.h"

void LightBlinkAction::handle(SecurityManager* mgr) {
    for (int i = 0; i < 3; ++i) {
        if (checkInterruption(mgr)) return;
        std::cout << "[LIGHT] Blink" << std::endl;
        Sleep(1);
    }
    handleNext(mgr);
}
