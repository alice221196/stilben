#ifndef FINAL_ACTION_HH
#define FINAL_ACTION_HH

#include <G4VUserActionInitialization.hh>
#include <StepAction.hh>
#include <PrimaryPart.hh>
#include <EventAct.hh>
#include <RunAct.hh>
#include <TrackEvent.hh>

class Action: public G4VUserActionInitialization{
public:
	Action();
	~Action();
    virtual void Build() const;
};
#endif
