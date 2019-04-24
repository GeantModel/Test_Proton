//
// Created by student on 08.05.18.
//

#ifndef TEMPLATE_PRIMARYGEN_HH
#define TEMPLATE_PRIMARYGEN_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include "Command.hh"

class PrimaryGen: public G4VUserPrimaryGeneratorAction{
private:

    G4ParticleGun* gun;
    G4ThreeVector pos_vect;
//    Command * detCommand;
    G4double Energy;
    G4int number;
public:
    PrimaryGen();

    virtual ~PrimaryGen();

    void GeneratePrimaries(G4Event *anEvent) override;
    void setVector(G4ThreeVector newValue);
    void setEnergy(G4double newValue);

    double Counter = 0;
    double Sum = 0;
    double t2 =0;
    double t1 =0;
    double dt = 0;
    double PCounts = 1000;
    double Step = 1000;
};
#endif //TEMPLATE_PRIMARYGEN_HH
