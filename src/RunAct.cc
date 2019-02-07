#include <RunAct.hh>

// Обработчик событий на уровне Run - Сумма событий-Event, общая статистика

RunAct::RunAct() {
	//OutFile::Info("\RunAct.cc works");
}

RunAct::~RunAct() {
	//OutFile::Info("\RunAct.cc destructed");
}

time_t Start, End;
int RunNum = 0;

void RunAct::BeginOfRunAction(const G4Run* aRun) {
	G4cout << "\n--------- Run # "<<RunNum<<" --------\n" << G4endl;
	time(&Start);
}

void RunAct::EndOfRunAction(const G4Run* aRun) {
	time(&End);
	G4cout << " Time spent on this Run = " << difftime(End, Start)<<" seconds"<< G4endl;
	RunNum++;
}