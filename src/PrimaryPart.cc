#include <PrimaryPart.hh>

PrimaryPart::PrimaryPart() {
	GGamma = new G4ParticleGun(1);
	//GGamma->SetParticleDefinition(G4::GammaDefinition());
	G4ParticleDefinition *n = G4ParticleTable::GetParticleTable()->FindParticle("neutron");
	GGamma->SetParticleDefinition(n);
	GGamma->SetParticleEnergy((2.5)*MeV);
	//gunMes = new GunMes(this);
}

PrimaryPart::~PrimaryPart() {}

//генерация излучения
void PrimaryPart::GeneratePrimaries(G4Event* anEvent) {
	
	
	GGamma->SetParticlePosition({ 0,-200 * mm,0 });
	GGamma->SetParticleMomentumDirection({G4RandFlat::shoot(-1,1),G4RandFlat::shoot(-1,1),G4RandFlat::shoot(-1,1)});
	GGamma->GeneratePrimaryVertex(anEvent);

}

//GunMes::~GunMes() {};