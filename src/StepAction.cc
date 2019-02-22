#include <StepAction.hh>
#include <EventAct.hh>//подключаем библиотеку с используемым счетчиком

// Обработчик событий на уровне Step - просчет отдельного шага/акта взаимодействия

void StepAct::UserSteppingAction(const G4Step* step) {

	G4double StepLength = step->GetStepLength(); //извлекаем инфу из шага
	EventAct::StepLengthCounter(StepLength);	//передаем инфу в другой класс (на уровень выше)

}
