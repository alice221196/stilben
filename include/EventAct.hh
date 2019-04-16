#pragma once

#include <G4UserEventAction.hh>
#include "G4Event.hh"

class EventAct : public G4UserEventAction {
public:
	EventAct();
	 ~EventAct();


	void BeginOfEventAction(const G4Event*);
	void EndOfEventAction(const G4Event*);
	static void addParticle(char type, int count);
	static int c_p, c_n;
};
