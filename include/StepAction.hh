//#ifndef M_DGW_4_STEPACTION_HH
//#define M_DGW_4_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <G4Step.hh>

class StepAct :public G4UserSteppingAction {
public:
	StepAct() {}
	~StepAct() {}
	void UserSteppingAction(const G4Step*);
};


//#endif