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
    mName = "G4_BGO";
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

    auto box = new G4Box("box",box_size/2.,box_size/2., box_size/2.);
    auto box_log = new G4LogicalVolume(box,G4NistManager::Instance()->FindOrBuildMaterial("G4_C"),"box_log");
    box_log->SetVisAttributes(G4Colour::Red());
   new G4PVPlacement(0,G4ThreeVector(),box_log,"box_pvp",world_log,false,0);

    auto shpere = new G4Sphere("shphere",55*cm/2.,75*cm/2.,0, 360*deg, 0, 360*deg);
    auto shpere_log = new G4LogicalVolume(shpere,G4NistManager::Instance()->FindOrBuildMaterial("G4_BGO"),"shpere_log");
    shpere_log->SetVisAttributes(G4VisAttributes::Invisible);
    new G4PVPlacement(0,G4ThreeVector(),shpere_log,"shphere_pvp",world_log,false,0);
    return new G4PVPlacement(nullptr,G4ThreeVector(),world_log,"world_pvp", nullptr,false,0);

    /*auto box = new G4Box("box",box_size/2.,box_size/2., box_size/2.);
    auto box_log = new G4LogicalVolume(box,G4NistManager::Instance()->FindOrBuildMaterial(mName),"box_log");
    box_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(nullptr,G4ThreeVector(),box_log,"box_pvp",world_log,false,0);
    return new G4PVPlacement(nullptr,G4ThreeVector(),world_log,"world_pvp", nullptr,false,0);*/



}

void Geometry::setSize(G4double newSize) {
     Geometry::box_size = newSize;
     G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
     G4RunManager::GetRunManager()->ReinitializeGeometry();
}
void Geometry::setMaterial(G4String newBoxMaterial) {
     Geometry::mName = newBoxMaterial;
}

