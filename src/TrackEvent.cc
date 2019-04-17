#include "TrackEvent.hh"
#include "EventAct.hh"
#include "RunAct.hh"


int TrackAction::c_p = 0;
int TrackAction::c_n = 0;

double lostEnergy;

void TrackAction::PreUserTrackingAction(const G4Track *track) {
	c_n = c_p = 0;
	lostEnergy = 0;

}
void TrackAction::addParticle_0(char part) {
	if (part == 1) {
		c_p++;
	}
	else{
		c_n++;
	}
}

void TrackAction::getLostEnergy(double Energy) {
	lostEnergy += Energy; 
}


void TrackAction::PostUserTrackingAction(const G4Track* track) {
	RunAct::getLostEnergy(lostEnergy);
	//EventAct::addParticle(1, c_p);
	//if (c_n > 0) {
		//EventAct::addParticle(0, c_n);
	//}
}
