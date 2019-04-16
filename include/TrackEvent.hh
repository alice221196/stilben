#pragma once

#include <G4UserTrackingAction.hh>
#include <G4ParticleDefinition.hh>
#include <G4Track.hh>


class TrackAction : public G4UserTrackingAction {
public:
	TrackAction() {};
	void PreUserTrackingAction(const G4Track *track) override;
	void PostUserTrackingAction(const G4Track* track) override;
	static int c_p, c_n;
	static void addParticle_0(char part);
};