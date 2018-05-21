//
// Created by student on 12.05.18.
//

#ifndef M_DGW_5_COMMAND_HH
#define M_DGW_5_COMMAND_HH
#include <G4UImessenger.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWith3Vector.hh>
#include "Geometry.hh"
#include "PrimaryGen.hh"
#include "StepAction.hh"
#include "EventAction.hh"

class Geometry;
class PrimaryGen;
class StepAction;
class EventAction;
class Command: public G4UImessenger{

    G4UIcmdWithADouble *setSize;
    G4UIcmdWithAString *setMaterial;
    G4UIcmdWith3Vector *setVector;
    G4UIcmdWithAString *setName;
    G4UIcmdWithADouble *setEvent;
    G4UIcmdWithADouble *setEnergy;
    G4UIcommand * cmd;
    Geometry* my_command_geometry;
    PrimaryGen* my_command_gen;
    StepAction* my_command_step;
    EventAction* my_command_event;
public:
    Command(Geometry* geom);
    Command(PrimaryGen* gen);
    Command(StepAction* step);
    Command(EventAction* event);
    ~Command();
    void SetNewValue(G4UIcommand *command, G4String newValue) override;

};
#endif //M_DGW_5_COMMAND_HH
