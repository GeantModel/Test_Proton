//
// Created by student on 08.05.18.
//

#include <G4Event.hh>
#include <PrimaryGen.hh>
#include <G4Gamma.hh>
#include "G4SystemOfUnits.hh"
void PrimaryGen::GeneratePrimaries(G4Event *anEvent) {
    gun->GeneratePrimaryVertex(anEvent);
}

PrimaryGen::PrimaryGen() {
    detCommand = new Command(this);
    pos_vect.set(0,0,-10*cm);
    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
    gun->SetParticlePosition(pos_vect);
    gun->SetParticleEnergy(661*keV);
}

PrimaryGen::~PrimaryGen() {
    delete gun;
    delete detCommand;
}

void PrimaryGen::setVector(G4ThreeVector newValue) {
    PrimaryGen::pos_vect = newValue;
}

