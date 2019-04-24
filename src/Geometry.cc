#include <G4Orb.hh>
#include <G4Colour.hh>
#include "Geometry.hh"
#include <G4VisAttributes.hh>
#include <G4Cons.hh>
#include <G4Para.hh>
#include <G4Tubs.hh>
#include <G4IntersectionSolid.hh>
#include <G4SubtractionSolid.hh>
#include <G4UnionSolid.hh>
#include <iostream>

Geometry::Geometry() {
    world_sizeXYZ   = 3 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_Galactic");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    logicWorld->SetVisAttributes(G4VisAttributes::Invisible);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

Geometry::~Geometry() {}

G4VPhysicalVolume* Geometry::Construct(){

    G4Material *polystyrene = nist->FindOrBuildMaterial("G4_POLYSTYRENE");

    G4Element *Y  = nist->FindOrBuildElement("Y");
    G4Element *Al = nist->FindOrBuildElement("Al");
    G4Element *O  = nist->FindOrBuildElement("O");
    G4Element *Br = nist->FindOrBuildElement("Br");
    G4Element *Ce = nist->FindOrBuildElement("Ce");
    G4Element *Lu = nist->FindOrBuildElement("Lu");
    G4Element *Si = nist->FindOrBuildElement("Si");

    G4Material *YAP = new G4Material("YAP", 5.37*g/cm3,3, kStateSolid);
    YAP->AddElement(Y,1);
    YAP->AddElement(Al,1);
    YAP->AddElement(O,3);


    G4Material *CeBr = new G4Material("CeBr", 5.1*g/cm3,2, kStateSolid);
    CeBr->AddElement(Ce,1);
    CeBr->AddElement(Br,3);

    G4Material *LYSO = new G4Material("LYSO", 7.15*g/cm3,4, kStateSolid);
    LYSO->AddElement(Lu,1);
    LYSO->AddElement(Y,1);
    LYSO->AddElement(Si,1);
    LYSO->AddElement(O,5);

    std::ofstream fout("../material.txt");
    fout<<polystyrene<<'\n';
    fout<<YAP<<'\n';
    fout<<CeBr<<'\n';
    fout<<LYSO<<'\n';

    G4Tubs *scin_CH = new G4Tubs("scin_CH", 0, 2.5*cm, 5*cm, 0, 360*deg);
    G4LogicalVolume *scin_CH_log = new G4LogicalVolume(scin_CH, polystyrene, "scin_CH_log");
    scin_CH_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(new G4RotationMatrix(0,0,0),G4ThreeVector(32.5*cm,0,0),scin_CH_log,"scin_CH_PVP",logicWorld,false,0);


    return physWorld;
}