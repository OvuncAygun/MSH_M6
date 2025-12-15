#pragma once
#include "EmergencyHandler.h"

class AlarmAction : public EmergencyHandler {
public:
    void handle(SecurityManager* mgr);
};