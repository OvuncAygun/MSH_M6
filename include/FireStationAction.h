#pragma once
#include "EmergencyHandler.h"

class FireStationAction : public EmergencyHandler {
public:
    void handle(SecurityManager* mgr);
};