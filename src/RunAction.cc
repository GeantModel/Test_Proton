
#include <RunAction.hh>
#include <StepAction.hh>
#include <EventAction.hh>
#include <map>
#include <G4SystemOfUnits.hh>
#include <fstream>

RunAction::RunAction() {
    result = new std::map<G4double , G4int >;
}
RunAction::~RunAction() {
    delete result;
}
void RunAction::BeginOfRunAction(const G4Run *aRun) {
    result->clear();
    int nStep = 100;
    G4double eMax = 10 *MeV;
    for (int i=1; i<nStep; i++) {
        result->emplace(i*eMax/nStep, 0);
    }
}
void RunAction::AddEvent(G4double energy) {
    result->lower_bound(energy)->second++;
}
/*void RunAction::Sum(G4int sum) {
    sumGamma+=sum;
}*/
void RunAction::EndOfRunAction(const G4Run *aRun) {
    std::fstream fout("../result.txt", std::ios::out);
    for (auto &it: *result)
        fout<<it.first<<" | "<<it.second<<'\n';
    fout.close();
    //std::cout<<"СУММА ГАММА-КВАНТОВ ЗА ВСЕ СОБЫТИЯ = "<<sumGamma<<'\n';
}

