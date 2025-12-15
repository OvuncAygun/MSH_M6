#pragma once
#include "EmergencyHandler.h"

class LightBlinkAction : public EmergencyHandler {
public:
    void handle(SecurityManager* mgr);
};