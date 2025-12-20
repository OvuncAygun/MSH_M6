#pragma once

#include "ISecurityManager.h"
#include "IDeviceManager.h"
#include "ILogger.h"

class MSH_M6 {
public:
    MSH_M6();
    ~MSH_M6();

    void setDeviceManager(IDeviceManager* deviceManager);
    void setLogger(ILogger* logger);
    void initializeSecurityManager();

    ISecurityManager* getSecurityManager();

private:
    ISecurityManager* securityManager;
    ILogger* logger;
};