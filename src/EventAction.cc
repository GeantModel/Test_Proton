//
// Created by idalov on 12.05.18.
//

#include <RunAction.hh>
#include <StepAction.hh>
#include <EventAction.hh>

EventAction::EventAction(RunAction *runAction) : runAction(runAction) {
    detCommand = new Command(this);
}
void EventAction::BeginOfEventAction(const G4Event *anEvent) {
    EnergyDep = 0;
}
void EventAction::AddEnDep(G4double en){
    EnergyDep+=en;
}
void EventAction::EndOfEventAction(const G4Event *anEvent) {
    runAction->AddEvent(EnergyDep);
}

void EventAction::setEvent(G4double newValue) {
     EventAction::Threshold = newValue;
}

