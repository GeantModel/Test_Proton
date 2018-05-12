//
// Created by student on 12.05.18.
//

#include <G4UIcommand.hh>
#include <Command.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWith3Vector.hh>

void Command::SetNewValue(G4UIcommand *command, G4String newValue) {
    if(command == cmd)
        exit(80);
    if(command == setSize)
        my_command_geometry->setSize(setSize->GetNewDoubleValue(newValue));
    if(command == setMaterial)
        my_command_geometry->setMaterial(newValue);
    if(command==setVector)
        my_command_gen->setVector(setVector->GetNew3VectorValue(newValue));
    if(command==setName)
        my_command_step->setName(newValue);
    if(command == setEvent)
        my_command_event->setEvent(setEvent->GetNewDoubleValue(newValue));
}

Command::Command(Geometry* geom): my_command_geometry(geom){
    auto dir = new G4UIdirectory("/my_command/");

    setSize = new G4UIcmdWithADouble("/my_command/setSizeBox",this);
    setSize->SetGuidance("Select size ");
    setSize->SetParameterName("size", false);

    setMaterial = new G4UIcmdWithAString("/my_command/setBoxMaterial",this);
    setMaterial->SetGuidance("Select material");
    setMaterial->SetParameterName("name", false);

    cmd = new G4UIcommand("/my_command/exit",this);
}
Command::Command(PrimaryGen* gen): my_command_gen(gen) {
    auto dir = new G4UIdirectory("/my_command/");

    setVector = new G4UIcmdWith3Vector("/my_command/setVector",this);
    setVector->SetGuidance("Select vector ");
}

Command::Command(StepAction* step): my_command_step(step) {
    auto dir = new G4UIdirectory("/my_command/");

    setName = new G4UIcmdWithAString("/my_command/setname",this);
    setName->SetGuidance("Select vector ");

}
Command::Command(EventAction* event): my_command_event(event) {
    auto dir = new G4UIdirectory("/my_command/");

    setEvent = new G4UIcmdWithADouble("/my_command/setEvent",this);
    setEvent->SetGuidance("Select vector ");

}
Command::~Command() {}

