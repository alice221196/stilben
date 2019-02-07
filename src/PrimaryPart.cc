#include <PrimaryPart.hh>

PrimaryPart::PrimaryPart() {
	GGamma = new G4ParticleGun(1);
	GGamma->SetParticleDefinition(G4Gamma::GammaDefinition());
	
	//gunMes = new GunMes(this);
}

PrimaryPart::~PrimaryPart() {}

//генерация излучения
void PrimaryPart::GeneratePrimaries(G4Event* anEvent) {
	
	GGamma->SetParticleEnergy((100)*keV);
	GGamma->SetParticlePosition(G4ThreeVector(0,0,0));
	GGamma->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
	GGamma->GeneratePrimaryVertex(anEvent);

}

//GunMes::~GunMes() {};