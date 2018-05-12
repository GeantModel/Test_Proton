//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_EVENTACTION_HH
#define TEMPLATE_EVENTACTION_HH

#include <G4UserEventAction.hh>
#include <pwdefs.hh>
#include "Command.hh"

class RunAction;

class EventAction: public G4UserEventAction{
    RunAction* runAction;
    G4double Threshold;
private:
    Command* detCommand;
public:
    explicit EventAction(RunAction *runAction);
    void setEvent(G4double newValue);
};
#endif //TEMPLATE_EVENTACTION_HH
