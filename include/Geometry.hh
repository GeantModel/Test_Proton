//
// Created by student on 08.05.18.
//

#ifndef TEMPLATE_GEOMETRY_HH
#define TEMPLATE_GEOMETRY_HH

#include <G4VUserDetectorConstruction.hh>
#include "G4NistManager.hh"
class Command;
class Geometry: public G4VUserDetectorConstruction{

public:
    G4VPhysicalVolume *Construct() override;
    Geometry();
    virtual ~Geometry();

private:
    G4double box_size;
    G4String mName;
    G4NistManager* nist;
    Command* detCommand;

public:
    void setSize(G4double newSize);
    void setMaterial(G4String newBoxMaterial);
};
#endif //TEMPLATE_GEOMETRY_HH
