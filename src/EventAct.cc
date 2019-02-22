#include <EventAct.hh>

// Обработчик событий на уровне Event - от начала запуска частицы до ее поглощения

EventAct::EventAct() {
	//OutFile::Info("\"EventAct.cc\" works");
}
EventAct::~EventAct() {}

int SLcounter=0;

void EventAct::StepLengthCounter(G4double count1) { //описание функции приема значения из шага
	SLcounter ++;
	G4cout << "Step N= " << SLcounter << "\t, Length=" << count1 << G4endl; //debug-инфо.
};

void EventAct::BeginOfEventAction(const G4Event * EVE) {
	//G4cout << "BeginWorks\t" << EVE->GetEventID() << G4endl;
	SLcounter = 0; //обнуление счетчика каждый раз при запуске единичного события
};

void EventAct::EndOfEventAction(const G4Event *EVE) {
		
};