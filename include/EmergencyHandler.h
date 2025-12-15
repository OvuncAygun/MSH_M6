#pragma once

#include "IEmergencyHandler.h"

class EmergencyHandler : public IEmergencyHandler {
protected:
    IEmergencyHandler* nextHandler;
    ILogger* logger;

    void handleNext(SecurityManager* mgr);

public:
    EmergencyHandler();
    virtual ~EmergencyHandler();

    void setNext(IEmergencyHandler* next);
    void setLogger(ILogger* logger);

    virtual void handle(SecurityManager* mgr) = 0;
    bool checkInterruption(SecurityManager* mgr);
};