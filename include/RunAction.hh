//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_RUNACTION_HH
#define TEMPLATE_RUNACTION_HH

#include <G4UserRunAction.hh>
#include <map>

class RunAction: public G4UserRunAction{
public: RunAction();
        ~RunAction();
        void BeginOfRunAction(const G4Run* aRun);
        void EndOfRunAction(const G4Run* aRun);
        void AddEvent(G4double energy);

private:
    std::map<G4double ,G4int > *result;
};
#endif //TEMPLATE_RUNACTION_HH
