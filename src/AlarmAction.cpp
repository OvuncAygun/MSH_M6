#include "AlarmAction.h"
#include "SecurityManager.h"
#include <iostream>
#include "sleep.h"

void AlarmAction::handle(SecurityManager* mgr) {
    if (mgr) {
        std::cout << "[ALARM] Activated" << std::endl;

        mgr->setIsAlarmActive(true);

        Sleep(2000);

        handleNext(mgr);
    }
}
