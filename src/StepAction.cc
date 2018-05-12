//
// Created by idalov on 12.05.18.
//

#include <StepAction.hh>

StepAction::StepAction(EventAction *_event) : event(_event) {
    detCommand = new Command(this);
}


void StepAction::UserSteppingAction(const G4Step *step) {}

void StepAction::setName(G4String newValue) {
     StepAction::pName = newValue;
}