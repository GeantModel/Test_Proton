//
// Created by idalov on 12.05.18.
//

#include <RunAction.hh>
#include <StepAction.hh>
#include <EventAction.hh>
#include <G4SystemOfUnits.hh>
#include "G4Step.hh"


StepAction::StepAction(EventAction *event) : event(event) {
    detCommand = new Command(this);
}


void StepAction::UserSteppingAction(const G4Step *step) {
    int num = 0;
//    if (step->GetPostStepPoint()->GetPhysicalVolume() != nullptr)
        if (//step->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "world_pvp"
            step->GetTrack()->GetVolume()->GetName() == "box_bgo_pvp"
            && step->GetTotalEnergyDeposit() > 0)
         event->AddEnDep(step->GetTotalEnergyDeposit());
}

void StepAction::setName(G4String newValue) {
     StepAction::pName = newValue;
     exit(77);
}

/* if (step->GetPostStepPoint()->GetPhysicalVolume() != nullptr)
        if (step->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "world_pvp"
            && step->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "shphere_pvp"
            && step->GetTrack()->GetKineticEnergy() > 3.2 * MeV
            && step->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma")
            //event->AddEnDep(step->GetTotalEnergyDeposit());
            event->AddGamma(1);*/