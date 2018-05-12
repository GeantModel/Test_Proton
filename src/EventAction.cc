//
// Created by idalov on 12.05.18.
//

#include <EventAction.hh>

EventAction::EventAction(RunAction *_runAction) : runAction(_runAction) {
    detCommand = new Command(this);
}

void EventAction::setEvent(G4double newValue) {
     EventAction::Threshold = newValue;
}

