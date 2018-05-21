//
// Created by idalov on 12.05.18.
//

#include <RunAction.hh>
#include <StepAction.hh>
#include <EventAction.hh>
#include "G4Step.hh"


StepAction::StepAction(EventAction *event) : event(event) {
    detCommand = new Command(this);
}


void StepAction::UserSteppingAction(const G4Step *step) {
    if(step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName()=="G4_BGO")
        event->AddEnDep(step->GetTotalEnergyDeposit());
}

void StepAction::setName(G4String newValue) {
     StepAction::pName = newValue;
     exit(77);
}