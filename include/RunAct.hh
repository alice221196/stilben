#pragma once

#include <G4UserRunAction.hh>
#include <DataWriter.hh>
#include <G4Run.hh>
#include "globals.hh"
#include <ctime>
#define ch_c 100

class RunAct : public G4UserRunAction {
public:
	
	RunAct();
	 ~RunAct();
	
	void BeginOfRunAction(const G4Run*);
	void EndOfRunAction(const G4Run*);
	static void addParticle(char type, int count);
	static void getLostEnergy(double Energy); 
	static int c_p, c_n;
	static double spectr[ch_c]; 


};
