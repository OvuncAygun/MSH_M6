#include "PoliceCallAction.h"
#include <iostream>

void PoliceCallAction::handle(SecurityManager*) {
    std::cout << "Calling police..." << std::endl;
    printf("Calling fire station...");
}