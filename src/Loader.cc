#include <Loader.hh>
#include <Geometry.hh>
#include <Action.hh>
#include <G4MTRunManager.hh>
#include <QGSP_BERT_HP.hh>

Loader::Loader(int argc, char **argv) {
#ifdef G4MULTITHREADED
    runManager = new G4MTRunManager;
    runManager->SetNumberOfThreads(G4Threading::G4GetNumberOfCores());
#else
    runManager = new G4RunManager;
#endif
    runManager->SetUserInitialization(new Geometry());
    runManager->SetUserInitialization(new QGSP_BERT_HP);
    runManager->SetUserInitialization(new Action());
    runManager->Initialize();
#ifdef G4VIS_USE
    // Initialize visualization
    visManager = new G4VisExecutive;
    visManager->Initialize();
#endif
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
	
    if (argc != 1) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    } else {
        // interactive mode : define UI session
#ifdef G4UI_USE
		G4UIExecutive *ui = new G4UIExecutive(argc, argv, "qt"); //Here we can redefine win32/qt interface
#ifdef G4VIS_USE
        UImanager->ApplyCommand("/control/execute init_vis.mac");
#else
        UImanager->ApplyCommand("/control/execute init.mac");
#endif
        ui->SessionStart();//and this two
        delete ui;
#endif
    }
}

Loader::~Loader(){
    delete visManager;
    delete runManager;
}