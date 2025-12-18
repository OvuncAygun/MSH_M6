#pragma once

#include "ISecurityManager.h"

class IEmergencyHandler;

class SecurityManager : public ISecurityManager {
private:
    bool systemArmed;
    bool alarmActive;
    bool stopFlag;

    IEmergencyHandler* motionChain;
    IEmergencyHandler* smokeChain;

public:
    SecurityManager();
    ~SecurityManager();

    bool getIsSystemArmed();
    void setIsSystemArmed(bool isSystemArmed);

    bool getIsAlarmActive();
    void setIsAlarmActive(bool isAlarmActive);

    void onMotionDetected();
    void onSmokeDetected();
    void stopSequence();

    bool isSequenceStopped() const;

    void setMotionChain(IEmergencyHandler* handler);
    void setSmokeChain(IEmergencyHandler* handler);
};