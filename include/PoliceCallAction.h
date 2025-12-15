#pragma once
#include "EmergencyHandler.h"

class PoliceCallAction : public EmergencyHandler {
public:
    void handle(SecurityManager* mgr);
};