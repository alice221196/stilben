//#pragma once

#include <G4UserRunAction.hh>
#include <DataWriter.hh>
#include <G4Run.hh>
#include "globals.hh"
#include <ctime>

class RunAct : public G4UserRunAction {
public:
	
	RunAct();
	 ~RunAct();
	
	void BeginOfRunAction(const G4Run*);
	void EndOfRunAction(const G4Run*);
};
