#pragma once

class ISecurityManager {
public:
    virtual ~ISecurityManager() = 0;

    virtual bool getIsSystemArmed() = 0;
    virtual void setIsSystemArmed(bool isSystemArmed) = 0;

    virtual bool getIsAlarmActive() = 0;
    virtual void setIsAlarmActive(bool isAlarmActive) = 0;

    virtual void onMotionDetected(int alarmDuration) = 0;
    virtual void onSmokeDetected(int alarmDuration) = 0;
    virtual void stopSequence() = 0;
};