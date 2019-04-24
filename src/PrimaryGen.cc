//
// Created by student on 08.05.18.
//

#include <G4Event.hh>
#include <PrimaryGen.hh>
#include <G4Gamma.hh>
#include <G4Neutron.hh>
#include <Randomize.hh>
#include "G4SystemOfUnits.hh"

using namespace std;

PrimaryGen::PrimaryGen() {
    Energy = 661;
//    detCommand = new Command(this);
    pos_vect.set(0,0,0);
    number = 1;
}
void PrimaryGen::GeneratePrimaries(G4Event *anEvent) {
    gun = new G4ParticleGun(number);
    gun->SetParticleEnergy(14*MeV);
    gun->SetParticleDefinition(G4Neutron::Neutron());

    G4double cosTheta = 2*G4UniformRand() - 1., phi = twopi*G4UniformRand();
    G4double sinTheta = std::sqrt(1. - cosTheta*cosTheta);
    G4double ux = sinTheta*std::cos(phi),
            uy = sinTheta*std::sin(phi),
            uz = cosTheta;

  //  gun->SetParticleMomentumDirection(G4ThreeVector(ux, uy, uz));
    gun->SetParticleMomentumDirection(G4ThreeVector(1,0,0));
    gun->SetParticlePosition(pos_vect);
    gun->GeneratePrimaryVertex(anEvent);

    Counter += 1;
    Sum += 1;

    double t = clock();

    if (Sum == (Step/2))
    {
        t1 = t/1000000;
    }

    if (Sum == (Step/2+100))
    {
        t2 = t/1000000;
    }

    dt = t2 - t1;

    if (Counter == Step)
    {
        cout << "Amount of shooted particle: " << Sum << endl;
        cout << "Time from start, s = " << t / 1000000 << endl;
    //    cout << "Time left, s = " << dt * ((PCounts-Sum) /100) << endl;
        cout << endl;
        Counter = 0;
    }
}

PrimaryGen::~PrimaryGen() {
    delete gun;
//    delete detCommand;
}

void PrimaryGen::setVector(G4ThreeVector newValue) {
    PrimaryGen::pos_vect = newValue;
}
void PrimaryGen::setEnergy(G4double newValue) {
    PrimaryGen::Energy = newValue;
}

