#include "TrackEvent.hh"
#include "EventAct.hh"


int TrackAction::c_p = 0;
int TrackAction::c_n = 0;

void TrackAction::PreUserTrackingAction(const G4Track *track) {
	c_n = c_p = 0;
}
void TrackAction::addParticle_0(char part) {
	if (part == 1) {
		c_p++;
	}
	else{
		c_n++;
	}
}

void TrackAction::PostUserTrackingAction(const G4Track* track) {
	EventAct::addParticle(1, c_p);
	if (c_n > 0) {
		EventAct::addParticle(0, c_n);
	}
}
