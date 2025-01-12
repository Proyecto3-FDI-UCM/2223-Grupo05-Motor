#include "AudioListener.h"
#include "GameObject.h"
#include "Transform.h"
#include "LMVector.h"
#include "LocoMotor_FMod/include/AudioListener.h"
#include "LocoMotor_FMod/include/AudioManager.h"
#include "LmVectorConverter.h"
#include "LogSystem.h"

using namespace LocoMotor;



AudioListener::AudioListener() {
	_list = nullptr;
	_lastPos = LMVector3();
}

AudioListener::~AudioListener() {
	delete _list;
}


void LocoMotor::AudioListener::PreStart() {
	_lastPos = gameObject->GetTransform()->GetPosition();
	_list->SetTransform(LmToFMod(_lastPos), LmToFMod(LMVector3()), LmToFMod(gameObject->GetTransform()->GetRotation().Forward()), LmToFMod(gameObject->GetTransform()->GetRotation().Up()));
}

void LocoMotor::AudioListener::Init(std::vector<std::pair<std::string, std::string>>& params) {
	InitComponent();
}

void LocoMotor::AudioListener::InitComponent() {
	_list = new FmodWrapper::AudioListener();
}


void LocoMotor::AudioListener::Update(float dt) {

	LMVector3 forwardVec = gameObject->GetTransform()->GetRotation().Forward() * -1;
	LMVector3 upwardVec = gameObject->GetTransform()->GetRotation().Up();

	LMVector3 vel = (gameObject->GetTransform()->GetPosition() - _lastPos) / (dt / 1000.f);

	unsigned short err = _list->SetTransform(LmToFMod(gameObject->GetTransform()->GetPosition()), LmToFMod(vel), LmToFMod(forwardVec), LmToFMod(upwardVec));

	if (err > 0) {
		LogSystem::GetInstance()->Save(0, "AudioListener::Update(): " + (std::string)FmodWrapper::AudioManager::GetInstance()->GetError(err));
	}

	_lastPos = gameObject->GetTransform()->GetPosition();
}


