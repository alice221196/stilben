//#pragma once

#include <G4UserEventAction.hh>
#include "G4Event.hh"

class EventAct : public G4UserEventAction {
public:
	EventAct();
	 ~EventAct();

	 static void StepLengthCounter(G4double SL); //функция приема значений (из шагов)

	void BeginOfEventAction(const G4Event*);
	void EndOfEventAction(const G4Event*);
};
