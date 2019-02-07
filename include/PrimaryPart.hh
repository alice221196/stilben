#ifndef FINAL_PRIMARYPART_HH
#define FINAL_PRIMARYPART_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <G4Gamma.hh>
#include <G4SystemOfUnits.hh>

//class G4Event;

class PrimaryPart: public G4VUserPrimaryGeneratorAction{
private:
	G4ParticleGun* GGamma; 

	G4ParticleGun*  fParticleGun;

public:
    PrimaryPart();
    ~PrimaryPart();

    virtual void GeneratePrimaries(G4Event* anEvent);
	const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
};

#endif //FINAL_PRIMARYPART_HH
