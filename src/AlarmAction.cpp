#include "AlarmAction.h"
#include <iostream>
#include <unistd.h>

void AlarmAction::handle(SecurityManager* mgr) {
    std::cout << "[ALARM] Activated" << std::endl;
    mgr->setIsAlarmActive(true);
    sleep(2);
    handleNext(mgr);
}