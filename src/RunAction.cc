
#include <RunAction.hh>
#include <StepAction.hh>
#include <EventAction.hh>
#include <map>
#include <G4SystemOfUnits.hh>
#include <fstream>

RunAction::RunAction() {
    result = new std::map<G4double , G4int >;
    result2 = new std::map<G4double , G4int >;
}
RunAction::~RunAction() {
    delete result;
    delete result2;
}
void RunAction::BeginOfRunAction(const G4Run *aRun) {
    result->clear();result2->clear();
    int nStep = 10000;
    G4double eMax = 15 *MeV;
    for (int i=1; i<nStep; i++) {
        result->emplace(i*eMax/nStep, 0);
        result2->emplace(i*eMax/nStep, 0);
    }
}
void RunAction::AddEvent(G4double energy) {
    result->lower_bound(energy)->second++;
}
void RunAction::AddEvent2(G4double energ) {
    result2->lower_bound(energ)->second++;
}
void RunAction::EndOfRunAction(const G4Run *aRun) {
    std::fstream fout("../result.txt", std::ios::out);
    for (auto &it: *result2)
        fout<<it.first<<" "<<it.second<<'\n';
    fout.close();
    //std::cout<<"СУММА ГАММА-КВАНТОВ ЗА ВСЕ СОБЫТИЯ = "<<sumGamma<<'\n';
}

