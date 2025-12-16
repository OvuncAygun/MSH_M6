#include "SecurityManager.h"
#include "IEmergencyHandler.h"

SecurityManager::SecurityManager()
    : systemArmed(false),
      alarmActive(false),
      stopFlag(false),
      motionChain(0),
      smokeChain(0) {}

bool SecurityManager::getIsSystemArmed() {
    return systemArmed;
}

void SecurityManager::setIsSystemArmed(bool armed) {
    systemArmed = armed;
}

bool SecurityManager::getIsAlarmActive() {
    return alarmActive;
}

void SecurityManager::setIsAlarmActive(bool active) {
    alarmActive = active;
}

void SecurityManager::onMotionDetected() {
    if (!systemArmed || !motionChain) return;
    stopFlag = false;
    motionChain->handle(this);
}

void SecurityManager::onSmokeDetected() {
    if (!smokeChain) return;
    stopFlag = false;
    smokeChain->handle(this);
}

void SecurityManager::stopSequence() {
    stopFlag = true;
}

bool SecurityManager::isSequenceStopped() const {
    return stopFlag;
}

void SecurityManager::setMotionChain(IEmergencyHandler* handler) {
    motionChain = handler;
}

void SecurityManager::setSmokeChain(IEmergencyHandler* handler) {
    smokeChain = handler;
}