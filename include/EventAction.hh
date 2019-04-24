//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_EVENTACTION_HH
#define TEMPLATE_EVENTACTION_HH

#include <G4UserEventAction.hh>
#include <pwdefs.hh>
#include "Command.hh"
#include "vector"

using namespace std;

class RunAction;

class EventAction: public G4UserEventAction{
      G4double Threshold;
private:
//    Command* detCommand;
    G4double EnergyDep;
    G4int num;
public:
    RunAction* runAction;
    vector<double> VecEnergy;
    explicit EventAction(RunAction *runAction);
    void setEvent(G4double newValue);
    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);
    void AddEnDep(G4double en);
    void AddGamma(G4int newvalue);
    };
#endif //TEMPLATE_EVENTACTION_HH
