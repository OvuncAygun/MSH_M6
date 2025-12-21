#include "FireStationAction.h"
#include <iostream>

void FireStationAction::handle(SecurityManager* mgr) {
    std::cout << "Calling fire station..." << std::endl;
}