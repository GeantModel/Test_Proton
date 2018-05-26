//
// Created by student on 08.05.18.
//

#include <G4VPhysicalVolume.hh>
#include <Geometry.hh>
#include <G4Box.hh>
#include <G4NistManager.hh>
#include "G4SystemOfUnits.hh"
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4RunManager.hh>
#include <Command.hh>
#include <G4GeometryManager.hh>
#include <G4PhysicalVolumeStore.hh>
#include <G4LogicalVolumeStore.hh>
#include <G4SolidStore.hh>
#include "G4Sphere.hh"


Geometry::Geometry() {
    box_size = 10*cm;
    mName = "G4_C";
    nist = G4NistManager::Instance();
    detCommand = new Command(this);
}
Geometry::~Geometry() {
    delete detCommand;
}
G4VPhysicalVolume *Geometry::Construct() {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    G4double world_size = 10*m;
    auto world = new G4Box("world", world_size/2.,world_size/2.,world_size/2.);
    auto world_log = new G4LogicalVolume(world,G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"),"world_log");
    world_log->SetVisAttributes(G4VisAttributes::Invisible);

    auto box_pb = new G4Box("box_pb",52*cm/2.,20*cm/2., 20*cm/2.);
    auto box_pb_log = new G4LogicalVolume(box_pb,G4NistManager::Instance()->FindOrBuildMaterial("G4_C"),"box_pb_log");
    box_pb_log->SetVisAttributes(G4Colour::Green());
    new G4PVPlacement(0,G4ThreeVector(0,0,0),box_pb_log,"box_pb_pvp",world_log,false,0);

    G4Isotope *Bi209 = new G4Isotope("Bi209", 83, 209, 208.9804*g/mole);
    G4Isotope *Ge73 = new G4Isotope("Ge73", 32, 73, 72.64*g/mole);
    G4Isotope *O16 = new G4Isotope("O16", 8, 16, 15.999 *g/mole);

    G4Element *Bi = new G4Element("Vismut","Bi", 1);
    Bi->AddIsotope(Bi209, 1);
    G4Element *Ge = new G4Element("Germanii","Ge", 1);
    Ge->AddIsotope(Ge73, 1);
    G4Element *O = new G4Element("Kislorod","O", 1);
    O->AddIsotope(O16, 1);

    G4Material *BGO = new G4Material("BGO", 7.13*g/cm3, 3, kStateSolid, 293*kelvin, 1.5e7*pascal);
    BGO->AddElement(Bi, 21.054*perCent);
    BGO->AddElement(Ge, 15.789*perCent);
    BGO->AddElement(O, 63.157*perCent);

    std::ofstream fout("../material.txt");
    fout<<BGO<<'\n';

    auto box_bgo = new G4Box("box_bgo",76*mm/2.,40*mm/2., 65*mm/2.);
    auto box_bgo_log = new G4LogicalVolume(box_bgo,BGO,"box_bgo_log");
    box_bgo_log->SetVisAttributes(G4Colour::Blue());
    new G4PVPlacement(0,G4ThreeVector(15*cm,0,20*cm),box_bgo_log,"box_bgo_pvp",world_log,false,0);

    auto rot = new G4RotationMatrix();
    rot->rotateY(45*deg);
    auto box_c = new G4Box("box_c",10*cm/2.,10*cm/2., 10*cm/2.);
    auto box_c_log = new G4LogicalVolume(box_c,G4NistManager::Instance()->FindOrBuildMaterial(mName),"box_c_log");
    box_c_log->SetVisAttributes(G4Colour::Yellow());
    new G4PVPlacement(rot,G4ThreeVector((5+44.6)*cm,0,20*cm),box_c_log,"box_c_pvp",world_log,false,0);

  /* auto shpere = new G4Sphere("shphere",55*cm/2.,75*cm/2.,0, 360*deg, 0, 360*deg);
    auto shpere_log = new G4LogicalVolume(shpere,G4NistManager::Instance()->FindOrBuildMaterial("G4_BGO"),"shpere_log");
    shpere_log->SetVisAttributes(G4VisAttributes::Invisible);
    new G4PVPlacement(0,G4ThreeVector(),shpere_log,"shphere_pvp",world_log,false,0);*/

    /*auto box = new G4Box("box",box_size/2.,box_size/2., box_size/2.);
    auto box_log = new G4LogicalVolume(box,G4NistManager::Instance()->FindOrBuildMaterial(mName),"box_log");
    box_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(nullptr,G4ThreeVector(),box_log,"box_pvp",world_log,false,0);*/

    return new G4PVPlacement(nullptr,G4ThreeVector(),world_log,"world_pvp", nullptr,false,0);

}

void Geometry::setSize(G4double newSize) {
     Geometry::box_size = newSize;
     G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
     G4RunManager::GetRunManager()->ReinitializeGeometry();
}
void Geometry::setMaterial(G4String newBoxMaterial) {
     Geometry::mName = newBoxMaterial;
     std::fstream fout("../result.txt", std::ios::out);
     fout<<"Material = "<<newBoxMaterial<<'\n';
}

