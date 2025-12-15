#include "EmergencyHandler.h"
#include "SecurityManager.h"
#include "external/ILogger.h"

EmergencyHandler::EmergencyHandler()
    : nextHandler(NULL), logger(NULL) {}

EmergencyHandler::~EmergencyHandler() {}

void EmergencyHandler::setNext(IEmergencyHandler* next) {
    nextHandler = next;
}

void EmergencyHandler::setLogger(ILogger* log) {
    logger = log;
}

void EmergencyHandler::handleNext(SecurityManager* mgr) {
    if (nextHandler && !checkInterruption(mgr)) {
        nextHandler->handle(mgr);
    }
}

bool EmergencyHandler::checkInterruption(SecurityManager* mgr) {
    return mgr->isSequenceStopped();
}