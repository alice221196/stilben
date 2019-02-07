#include <EventAct.hh>

// Обработчик событий на уровне Event - от начала запуска частицы до ее поглощения

EventAct::EventAct() {
	//OutFile::Info("\"EventAct.cc\" works");
}
EventAct::~EventAct() {}

void EventAct::BeginOfEventAction(const G4Event * EVE){
	//G4cout << "BeginWorks\t" << EVE->GetEventID() << G4endl;
};

void EventAct::EndOfEventAction(const G4Event *EVE){
};
