//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_RUNACTION_HH
#define TEMPLATE_RUNACTION_HH

#include <G4UserRunAction.hh>
#include <map>
#include "vector"

using namespace std;

class RunAction: public G4UserRunAction{
public: RunAction();
        ~RunAction();
        void BeginOfRunAction(const G4Run* aRun);
        void EndOfRunAction(const G4Run* aRun);
        void AddEvent(G4double energy);
        void AddEvent2(G4double energ);
        void Sum(vector<int> energ);

private:
    G4int sumGamma;
    map<G4double ,G4int > *result;
    map<G4double ,G4int > *result2;
};
#endif //TEMPLATE_RUNACTION_HH
