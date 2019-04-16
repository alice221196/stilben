#ifndef M_DGW_4_STEPACTION_HH
#define M_DGW_4_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <G4Step.hh>

class StepAct :public G4UserSteppingAction {
public:
	StepAct() {
		cnt_p = 0;
		cnt_n = 0;
	}
	~StepAct() {}
	void UserSteppingAction(const G4Step*);

private:
	unsigned cnt_p;
	unsigned cnt_n;
};


#endif