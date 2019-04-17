#include <Action.hh>


Action::Action() {
	//Logger::Info("\"General actions\" have been built");	// debug info
}

Action::~Action() {
	// Logger::Info("\"General actions\" have been destroyed");	// debug info
}

//	����������� ������, ������ �� ����������
void Action::Build()const {
    SetUserAction(new StepAct());
	SetUserAction(new RunAct);
	SetUserAction(new PrimaryPart);
	SetUserAction(new EventAct);
	SetUserAction(new TrackAction);
}
