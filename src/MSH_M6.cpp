#include "MSH_M6.h"
#include "SecurityChainBuilder.h"
#include "SecurityManager.h"

MSH_M6::MSH_M6() = default;
MSH_M6::~MSH_M6() = default;

void MSH_M6::setDeviceManager(IDeviceManager* deviceManager) {
    this->deviceManager = deviceManager;
}

void MSH_M6::setLogger(ILogger* logger) {
    this->logger = logger;
}

void MSH_M6::initializeSecurityManager() {
    securityManager = new SecurityManager();
    static_cast<SecurityManager*>(securityManager)->setDeviceManager(deviceManager);
    static_cast<SecurityManager*>(securityManager)->setLogger(logger);
    SecurityChainBuilder builder;
    builder.build(*static_cast<SecurityManager*>(securityManager));
}

ISecurityManager* MSH_M6::getSecurityManager() {
    return 0;
}