#include "FireStationAction.h"
#include <iostream>

void FireStationAction::handle(SecurityManager*) {
    std::cout << "Calling fire station..." << std::endl;
}