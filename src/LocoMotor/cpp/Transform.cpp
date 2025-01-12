#include "Transform.h"
#include "GameObject.h"
#include "Scene.h"
#include "RenderScene.h"
#include "RigidBody.h"
#include "Node.h"
#include "OgreManager.h"
#include "LmVectorConverter.h"



LocoMotor::Transform::Transform() {
	_position = LMVector3();
	_direction = LMQuaternion();
	_scale = LMVector3(1, 1, 1);

	_gObjNode = nullptr;
}

LocoMotor::Transform::~Transform() {
}


void LocoMotor::Transform::InitComponent() {
	gameObject->RegisterTransform(this);
	_gObjNode = OgreWrapper::OgreManager::GetInstance()->GetScene(gameObject->GetScene()->GetSceneName())->GetNode(gameObject->GetName());
}


void LocoMotor::Transform::Init(std::vector<std::pair<std::string, std::string>>& params) {
	gameObject->RegisterTransform(this);
	
	for (const auto& pair : params) {
		if (pair.first == "pos" || pair.first == "position") {
			unsigned char currAxis = 0;
			std::string num = "";
			LMVector3 result = LMVector3();
			for (const char c : pair.second) {
				if (c != ' ') {
					num += c;
				}
				else {
					float value = 0.f;
					try {
						value = std::stof(num);
					}
					catch (std::invalid_argument) {
						value = 0.f;
					}
					if (currAxis == 0) {
						result.SetX(value);
					}
					else if (currAxis == 1) {
						result.SetY(value);
					}
					else if (currAxis == 2) {
						result.SetZ(value);
					}
					currAxis++;
					num = "";
				}
			}
			float value = 0.0f;
			try {
				value = std::stof(num);
			}
			catch (std::invalid_argument) {
				value = 0.0f;
			}
			if (currAxis == 2) {
				result.SetZ(value);
			}
			_position = result;
		
		}
		else if (pair.first == "rot" || pair.first == "rotation") {
			unsigned char currAxis = 0;
			std::string num = "";
			LMVector3 result = LMVector3();
			for (const char c : pair.second) {
				if (c != ' ') {
					num += c;
				}
				else {
					float value = 0.f;
					try {
						value = std::stof(num);
					}
					catch (std::invalid_argument) {
						value = 0.f;
					}
					if (currAxis == 0) {
						result.SetX(value);
					}
					else if (currAxis == 1) {
						result.SetY(value);
					}
					else if (currAxis == 2) {
						result.SetZ(value);
					}
					currAxis++;
					num = "";
				}
			}
			float value = 0.0f;
			try {
				value = std::stof(num);
			}
			catch (std::invalid_argument) {
				value = 0.0f;
			}
			if (currAxis == 2) {
				result.SetZ(value);
			}
			_direction = result.AsRotToQuaternion();
			_direction.Normalize();
			_directionEuler = result;
		}
		else if (pair.first == "size" || pair.first == "scale") {
			unsigned char currAxis = 0;
			std::string num = "";
			LMVector3 result = LMVector3();
			for (const char c : pair.second) {
				if (c != ' ') {
					num += c;
				}
				else {
					float value = 0.f;
					try {
						value = std::stof(num);
					}
					catch (const char*) {
						value = 0.f;
					}
					if (currAxis == 0) {
						result.SetX(value);
					}
					else if (currAxis == 1) {
						result.SetY(value);
					}
					else if (currAxis == 2) {
						result.SetZ(value);
					}
					currAxis++;
					num = "";
				}
			}
			float value = 0.0f;
			try {
				value = std::stof(num);
			}
			catch (const char*) {
				value = 0.0f;
			}
			if (currAxis == 2) {
				result.SetZ(value);
			}
			_scale = result;
		}
	}
}

void LocoMotor::Transform::Start() {
	_gObjNode = OgreWrapper::OgreManager::GetInstance()->GetScene(gameObject->GetScene()->GetSceneName())->GetNode(gameObject->GetName());
	SetLocalPosition(_position);
	SetLocalEulerRotation(_directionEuler);
	SetLocalScale(_scale);
}

void LocoMotor::Transform::Update(const float dt) {
}


const LocoMotor::LMVector3& LocoMotor::Transform::GetPosition() {
	return _position;
}


void LocoMotor::Transform::SetPosition(const LMVector3& newPosition) {
	SetLocalPosition(newPosition);
	SetPhysPosition(newPosition);
}


const LocoMotor::LMQuaternion& LocoMotor::Transform::GetRotation() {
	return _direction;
}


void LocoMotor::Transform::SetRotation(const LMQuaternion& newRotation) {
	SetLocalRotation(newRotation);
	SetPhysRotation(newRotation);
}


const LocoMotor::LMVector3& LocoMotor::Transform::GetEulerRotation() {
	return _directionEuler;
}


void LocoMotor::Transform::SetEulerRotation(const LMVector3& newRotation) {
	SetLocalEulerRotation(newRotation);
	SetPhysEulerRotation(newRotation);
}


const LocoMotor::LMVector3& LocoMotor::Transform::GetSize() {
	return _scale;
}


void LocoMotor::Transform::SetSize(const LMVector3& newSize) {
	SetLocalScale(newSize);
	SetPhysScale(newSize);
}


void LocoMotor::Transform::SetUpwards(const LMVector3& newUpward) {
	double angle = GetRotation().Up().Angle(newUpward);
	if (angle == 0.) return;

	LMVector3 v1 = GetRotation().Up();
	LMVector3 v2 = newUpward;
	LMVector3 axis = LMVector3(
		v1.GetY() * v2.GetZ() - v1.GetZ() * v2.GetY(),
		v1.GetZ() * v2.GetX() - v1.GetX() * v2.GetZ(),
		v1.GetX() * v2.GetY() - v1.GetY() * v2.GetX());

	SetRotation(GetRotation().Rotate(axis, angle));
}


void LocoMotor::Transform::SetForward(const LMVector3& newForward) {
	double angle = GetRotation().Forward().Angle(newForward);
	if (angle == 0.) return;

	LMVector3 v1 = GetRotation().Forward();
	LMVector3 v2 = newForward;
	LMVector3 axis = LMVector3(
		v1.GetY() * v2.GetZ() - v1.GetZ() * v2.GetY(),
		v1.GetZ() * v2.GetX() - v1.GetX() * v2.GetZ(),
		v1.GetX() * v2.GetY() - v1.GetY() * v2.GetX());

	SetRotation(GetRotation().Rotate(axis, angle));
}


void LocoMotor::Transform::LookAt(const LMVector3& lookPos) {
	LMVector3 newForward = lookPos - GetPosition();
	SetForward(newForward);
}


void LocoMotor::Transform::LookAt(const LMVector3& lookPos, const LMVector3& up) {
	SetUpwards(up);
	LMVector3 newForward = lookPos - GetPosition();
	SetForward(newForward);
}


void LocoMotor::Transform::SetLocalPosition(const LMVector3& newPosition) {
	_position = newPosition;
	if(_gObjNode!=nullptr)
	_gObjNode->SetPosition((float)newPosition.GetX(), (float) newPosition.GetY(), (float) newPosition.GetZ());
}


void LocoMotor::Transform::SetLocalRotation(const LMQuaternion& newRotation) {
	_direction = newRotation;
	_direction.Normalize();
	if (_gObjNode != nullptr) {
		Ogre::Quaternion a = LmToOgre(newRotation);
		_gObjNode->SetOrientation(a);
	}
	_directionEuler = _direction.ToEuler();
}


void LocoMotor::Transform::SetLocalEulerRotation(const LMVector3& newRotation) {
	_direction = newRotation.AsRotToQuaternion();
	_direction.Normalize();
	
	if (_gObjNode != nullptr) {
		Ogre::Quaternion a = LmToOgre(newRotation.AsRotToQuaternion());
		_gObjNode->SetOrientation(a);
	}
	
	_directionEuler = newRotation;
}


void LocoMotor::Transform::SetLocalScale(const LMVector3& newSize) {
	_scale = newSize;
	if (_gObjNode != nullptr)
	_gObjNode->SetScale((float)newSize.GetX(), (float)newSize.GetY(), (float)newSize.GetZ());
}


void LocoMotor::Transform::SetPhysPosition(const LMVector3& newPosition) {
	RigidBody* rb = gameObject->GetComponent<RigidBody>();
	if (rb != nullptr) {
		rb->SetPosition(newPosition);
	}
}


void LocoMotor::Transform::SetPhysRotation(const LMQuaternion& newRotation) {
	RigidBody* rb = gameObject->GetComponent<RigidBody>();
	if (rb != nullptr) {
		rb->SetRotation(newRotation);
	}
}


void LocoMotor::Transform::SetPhysEulerRotation(const LMVector3& newRotation) {
	RigidBody* rb = gameObject->GetComponent<RigidBody>();
	if (rb != nullptr) {
		rb->SetRotation(newRotation.AsRotToQuaternion());
	}
}


void LocoMotor::Transform::SetPhysScale(const LMVector3& newsize) {
}


