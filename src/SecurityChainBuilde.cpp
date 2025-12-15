#include "SecurityChainBuilder.h"
#include "SecurityManager.h"
#include "AlarmAction.h"
#include "LightBlinkAction.h"
#include "PoliceCallAction.h"
#include "FireStationAction.h"

void SecurityChainBuilder::build(SecurityManager& mgr) {
    AlarmAction* a1 = new AlarmAction();
    LightBlinkAction* l1 = new LightBlinkAction();
    PoliceCallAction* p = new PoliceCallAction();

    a1->setNext(l1);
    l1->setNext(p);
    mgr.setMotionChain(a1);

    AlarmAction* a2 = new AlarmAction();
    LightBlinkAction* l2 = new LightBlinkAction();
    FireStationAction* f = new FireStationAction();

    a2->setNext(l2);
    l2->setNext(f);
    mgr.setSmokeChain(a2);
}