//
// Created by student on 08.05.18.
//

#include <G4MTRunManager.hh>
#include <Loader.hh>
#include <Geometry.hh>
#include <QBBC.hh>
#include <Action.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>

Loader::Loader(int argc, char** argv) {
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    CLHEP::HepRandom::setTheSeed(time(nullptr));

    runManager = new G4MTRunManager();
    runManager->SetNumberOfThreads(1);
    runManager->SetVerboseLevel(0);
    runManager->SetUserInitialization(new Geometry);
    auto ph = new QBBC;
    ph->SetVerboseLevel(0);
    runManager->SetUserInitialization(ph);
    runManager->SetUserInitialization(new Action);

    runManager->Initialize();

    auto visManager = new G4VisExecutive;
    visManager->Initialize();


    auto UImanager = G4UImanager::GetUIpointer();

    if (argc != 1) {
        std::string command = "/control/execute ";
        std::string fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    } else {

        G4UIExecutive *ui = new G4UIExecutive(argc, argv);

        UImanager->ApplyCommand("/control/execute init_vis.mac");

        ui->SessionStart();
        delete ui;
    }

    delete runManager;
}
