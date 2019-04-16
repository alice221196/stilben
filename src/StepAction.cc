#include <StepAction.hh>
//#include <EventAct.hh>//подключаем библиотеку с используемым счетчиком
#include <EventAct.hh>

// Обработчик событий на уровне Step - просчет отдельного шага/акта взаимодействия

void StepAct::UserSteppingAction(const G4Step* step) {
	if (step->GetPreStepPoint()->GetPhysicalVolume() != nullptr) {
		if (step->GetPreStepPoint()->GetPhysicalVolume()->GetLogicalVolume()->GetName() == "ST_log") {
			if (step->GetPreStepPoint()->GetMass() < 939. && step->GetPreStepPoint()->GetMass() > 938.) {
				//G4cout << "protons: " << ++cnt_p << G4endl;
				//TrackAction::addParticle_0(1);
				EventAct::addParticle(1, 1);
			}
			if (step->GetTrack()->GetParticleDefinition()->GetParticleName() == "neutron") {
				//G4cout << "neutrons: " << ++cnt_n << G4endl;
				//TrackAction::addParticle_0(0);
				EventAct::addParticle(0, 1);
			}
		}
	}
	
	G4double StepLength = step->GetStepLength(); //извлекаем инфу из шага

}
