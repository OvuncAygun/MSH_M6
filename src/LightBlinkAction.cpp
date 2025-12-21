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
        std::vector<IDevice*> lights = deviceMgr->getDeviceByType(DeviceType::TYPE_Light);
        if(i % 2 == 0){
            std::cout << "[LIGHT] Blinking lights ON." << std::endl;
        }
        else {
            std::cout << "[LIGHT] Blinking lights OFF." << std::endl;
        }
        for (IDevice* light : lights) {
            if(i % 2 == 0){
                light->poweron();
            }
            else {
                light->poweroff();
            }
        }
        
        mgr->checkAlarmDuration(1000);
        
        sleep_ms(1000);
    }
    handleNext(mgr);
}

