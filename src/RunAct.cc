#include <RunAct.hh>
#include "DataWriter.hh"

// Обработчик событий на уровне Run - Сумма событий-Event, общая статистика

RunAct::RunAct() {
	//OutFile::Info("\RunAct.cc works");
	for (int i = 0; i < ch_c; i++) {
		spectr[i] = 0;
	}
}

RunAct::~RunAct() {
	//OutFile::Info("\RunAct.cc destructed");
}

time_t Start, End;
int RunNum = 0;
int RunAct::c_p = 0;
int RunAct::c_n = 0;

void RunAct::addParticle(char type, int count) {
	if (type == 1) {
		c_p += count;
	}
	else {
		c_n += count;
	}

}
void RunAct::getLostEnergy(double Energy) {
	double width = 14. / ch_c;
	if (Energy <= 14) {
		spectr[(int)(Energy / width)]++;
	}
}

void RunAct::BeginOfRunAction(const G4Run* aRun) {
	G4cout << "\n--------- Run # "<<RunNum<<" --------\n" << G4endl;
	time(&Start);
}

void RunAct::EndOfRunAction(const G4Run* aRun) {
	time(&End);
	G4cout << " Time spent on this Run = " << difftime(End, Start)<<" seconds"<< G4endl;
	RunNum++;
	DataSaver::OpenFile("Spectrum.txt");
	DataSaver::AddData({ spectr,spectr+ch_c});
	DataSaver::CloseFile();
}