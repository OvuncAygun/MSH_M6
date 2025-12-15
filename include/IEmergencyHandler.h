#pragma once

class SecurityManager;
class ILogger;

class IEmergencyHandler {
public:
    virtual ~IEmergencyHandler() {}

    virtual void setNext(IEmergencyHandler* next) = 0;
    virtual void setLogger(ILogger* logger) = 0;

    virtual void handle(SecurityManager* mgr) = 0;
    virtual bool checkInterruption(SecurityManager* mgr) = 0;
};

