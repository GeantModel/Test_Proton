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
      G4double Threshold;
private:
    Command* detCommand;

    G4double EnergyDep;
public:
    RunAction* runAction;
    explicit EventAction(RunAction *runAction);
    void setEvent(G4double newValue);
    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);
    void AddEnDep(G4double en);
};
#endif //TEMPLATE_EVENTACTION_HH
