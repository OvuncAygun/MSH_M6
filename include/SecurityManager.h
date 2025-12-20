#pragma once

#include "ISecurityManager.h"
#include "IDeviceManager.h"
#include "ILogger.h"

class IEmergencyHandler;

class SecurityManager : public ISecurityManager {
private:
    bool systemArmed;
    bool alarmActive;
    bool stopFlag;
    int alarmDuration;

    IEmergencyHandler* motionChain;
    IEmergencyHandler* smokeChain;

    IDeviceManager* deviceManager;
    ILogger* logger;

public:
    SecurityManager();
    ~SecurityManager();

    IDeviceManager* getDeviceManager();
    void setDeviceManager(IDeviceManager* deviceManager);

    ILogger* getLogger();
    void setLogger(ILogger* logger);

    bool getIsSystemArmed();
    void setIsSystemArmed(bool isSystemArmed);

    bool getIsAlarmActive();
    void setIsAlarmActive(bool isAlarmActive);

    void onMotionDetected(int alarmDuration);
    void onSmokeDetected(int alarmDuration);
    void checkAlarmDuration(int duration);
    void stopSequence();

    bool isSequenceStopped() const;

    void setMotionChain(IEmergencyHandler* handler);
    void setSmokeChain(IEmergencyHandler* handler);
};