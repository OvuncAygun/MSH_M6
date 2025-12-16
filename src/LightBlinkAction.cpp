#include "LightBlinkAction.h"
#include "SecurityManager.h"
#include <iostream>
<<<<<<< HEAD
#include "sleep.h"
=======
#include <thread> 
#include <chrono>           
>>>>>>> 82f1aa695cdf534e71387a1363299e03497896e9

void LightBlinkAction::handle(SecurityManager* mgr) {
    if (!mgr) return;
    for (int i = 0; i < 3; ++i) {
        if (checkInterruption(mgr)) {
            std::cout << "[LIGHT] Blink sequence interrupted." << std::endl;
            return;
        }

        std::cout << "[LIGHT] Blink" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    handleNext(mgr);
}

