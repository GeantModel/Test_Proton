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
    Command * detCommand;
public:
    PrimaryGen();

    virtual ~PrimaryGen();

    void GeneratePrimaries(G4Event *anEvent) override;
    void setVector(G4ThreeVector newValue);
};
#endif //TEMPLATE_PRIMARYGEN_HH
