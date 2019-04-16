#include <EventAct.hh>
#include <RunAct.hh>
// Обработчик событий на уровне Event - от начала запуска частицы до ее поглощения

EventAct::EventAct() {
	//OutFile::Info("\"EventAct.cc\" works");
}
EventAct::~EventAct() {}

int EventAct::c_p = 0;
int EventAct::c_n = 0;

void EventAct::addParticle(char type, int count) {
	if (type == 1) {
		c_p += count;
	}
	else {
		c_n++;
	}
}

void EventAct::BeginOfEventAction(const G4Event * EVE) {
	c_p = c_n = 0;
};

void EventAct::EndOfEventAction(const G4Event *EVE) {
	RunAct::addParticle(1, c_p);
	if (c_n > 0) {
		RunAct::addParticle(0, c_n);
	}
};