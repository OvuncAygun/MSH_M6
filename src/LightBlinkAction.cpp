#include "LightBlinkAction.h"
#include "SecurityManager.h"
#include <iostream>
#include "sleep.h"
#include "DeviceType.h"
#include "IDevice.h"

void LightBlinkAction::handle(SecurityManager* mgr) {
    if (!mgr) return;
    for (int i = 0; i < 5; ++i) {
        if (checkInterruption(mgr)) {
            std::cout << "[LIGHT] Blink sequence interrupted." << std::endl;
            return;
        }

        IDeviceManager* deviceMgr = mgr->getDeviceManager();
        std::vector<IDevice*> lights = deviceMgr->getDevicesByType(DeviceType::LIGHT);
        for (IDevice* light : lights) {
            if(i % 2 == 0){
                light->poweron();
            }
            else {
                light->poweroff();
            }
        }
        
        mgr->checkAlarmDuration(1000);
        
        std::cout << "[LIGHT] Blink" << std::endl;
        Sleep(1000);
    }
    handleNext(mgr);
}

