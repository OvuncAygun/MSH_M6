#include "AlarmAction.h"
#include <iostream>
#include <windows.h>

void AlarmAction::handle(SecurityManager* mgr) {
    std::cout << "[ALARM] Activated" << std::endl;
    mgr->setIsAlarmActive(true);
    Sleep(2);
    handleNext(mgr);
}