#include "SecurityManager.h"
#include "IEmergencyHandler.h"

SecurityManager::SecurityManager()
    : systemArmed(false),
      alarmActive(false),
      stopFlag(false),
      motionChain(0),
      smokeChain(0) {}

SecurityManager::~SecurityManager() {};

IDeviceManager* SecurityManager::getDeviceManager() {
    return deviceManager;
}

void SecurityManager::setDeviceManager(IDeviceManager* deviceManager) {
    this->deviceManager = deviceManager;
}

ILogger* SecurityManager::getLogger() {
    return logger;
}

void SecurityManager::setLogger(ILogger* logger) {
    this->logger = logger;
}

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

void SecurityManager::onMotionDetected(int alarmDuration) {
    this->alarmDuration = alarmDuration;
    if (!systemArmed || !motionChain) return;
    stopFlag = false;
    motionChain->handle(this);
}

void SecurityManager::onSmokeDetected(int alarmDuration) {
    this->alarmDuration = alarmDuration;
    if (!smokeChain) return;
    stopFlag = false;
    smokeChain->handle(this);
}

void SecurityManager::checkAlarmDuration(int duration) {
    if (alarmDuration > 0 && duration >= alarmDuration) {
        stopSequence();
    }
    alarmDuration -= duration;
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