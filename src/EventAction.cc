//
// Created by idalov on 12.05.18.
//

#include <RunAction.hh>
#include <StepAction.hh>
#include <EventAction.hh>
#include <vector>

using namespace std;
EventAction::EventAction(RunAction *runAction) : runAction(runAction) {
//    detCommand = new Command(this);
}
void EventAction::BeginOfEventAction(const G4Event *anEvent) {
    EnergyDep = 0;
    num = 0;
    vector<double> VecEnergy ;
   // VecEnergy.clear();
}

void EventAction::AddEnDep(G4double en){
    EnergyDep+=en;
    VecEnergy.push_back(en);
}

/*void EventAction::AddGamma(G4int newvalue) {
    num++;
}*/
void EventAction::EndOfEventAction(const G4Event *anEvent) {
    runAction->AddEvent(EnergyDep);
    for (int i=0; i<VecEnergy.size(); i++){
        runAction->AddEvent2(VecEnergy[i]);
    //    cout<<" "<<VecEnergy[i];
    }
  //  cout<<"   РАЗМЕР ВЕКТОРА = "<<VecEnergy.size()<<'\n';
    //runAction->Sum(num);
    //G4cout<<"КОЛИЧЕСТВО ГАММА-КВАНТОВ  = "<<num<<'\n';
    VecEnergy.clear();
}

void EventAction::setEvent(G4double newValue) {
     EventAction::Threshold = newValue;
     abort();
}

