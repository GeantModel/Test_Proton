//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_STEPACTION_HH
#define TEMPLATE_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <G4String.hh>
#include "Command.hh"

class EventAction;
class StepAction : public G4UserSteppingAction{
       G4String pName;
private:
//    Command* detCommand;

public:
    EventAction* event;
    explicit StepAction(EventAction *event);
    void UserSteppingAction(const G4Step *step) override;

    void setName(G4String newValue);
};
#endif //TEMPLATE_STEPACTION_HH
