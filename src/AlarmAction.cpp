#include "AlarmAction.h"
#include "SecurityManager.h"
#include <iostream>
#include <thread>         
#include <chrono>

void AlarmAction::handle(SecurityManager* mgr) {
    if (mgr) {
        std::cout << "[ALARM] Activated" << std::endl;

        mgr->setIsAlarmActive(true);

        std::this_thread::sleep_for(std::chrono::seconds(2));

        handleNext(mgr);
    }
}
