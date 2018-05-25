//
// Created by student on 08.05.18.
//

#include <G4Event.hh>
#include <PrimaryGen.hh>
#include <G4Gamma.hh>
#include <G4Neutron.hh>
#include <Randomize.hh>
#include "G4SystemOfUnits.hh"

PrimaryGen::PrimaryGen() {
    Energy = 661;
    detCommand = new Command(this);
    pos_vect.set(0,0,-10*cm);
    number = 1;
}
void PrimaryGen::GeneratePrimaries(G4Event *anEvent) {
    gun = new G4ParticleGun(number);
    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());

   /* double x = 2*G4UniformRand()-1;
    double y = 2*G4UniformRand()-1;
    double z = 2*G4UniformRand()-1;
    double r = sqrt(x*x + y*y + z*z);
    gun->SetParticleMomentum(G4ThreeVector(x/r, y/r, z/r));*/

    gun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
    /*double R = 10*cm, px, py, pz;

    do {
        px = (2*G4UniformRand()-1) * cm;
        py = (2*G4UniformRand()-1) * cm;
        pz = (2*G4UniformRand()-1) * cm;
    } while (sqrt(px*px + py*py + pz*pz) > R);

    gun->SetParticlePosition(G4ThreeVector(px, py, pz));*/
    gun->SetParticlePosition(pos_vect);
    gun->SetParticleEnergy(14*MeV);
    gun->GeneratePrimaryVertex(anEvent);
   /* srand(time(NULL));
    double A = (rand()%10)/(10*1.0)+0.1;
    if ((A-0.4)>0) {
        gun = new G4ParticleGun(number);
        gun->SetParticleDefinition(G4Gamma::GammaDefinition());
        gun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
        gun->SetParticlePosition(pos_vect);
        gun->SetParticleEnergy(Energy*keV);
        gun->GeneratePrimaryVertex(anEvent);
   /* }
    else {
        gun = new G4ParticleGun(2*number);
        gun->SetParticleDefinition(G4Gamma::GammaDefinition());
        gun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
        gun->SetParticlePosition(pos_vect);
        gun->SetParticleEnergy(Energy*keV);
        gun->GeneratePrimaryVertex(anEvent);
    }*/
}
PrimaryGen::~PrimaryGen() {
    delete gun;
    delete detCommand;
}

void PrimaryGen::setVector(G4ThreeVector newValue) {
    PrimaryGen::pos_vect = newValue;
}
void PrimaryGen::setEnergy(G4double newValue) {
    PrimaryGen::Energy = newValue;
}

