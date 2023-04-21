#include "Scene.h"
#include "Camera.h"
#include "OgreManager.h"
#include "RenderScene.h"
#include "Node.h"
#include "Renderer3D.h"
#include "RigidBodyComponent.h"
#include "PhysicsManager.h"
#include "MeshRenderer.h"
#include "ParticleSystem.h"
#include "GameObject.h"

using namespace LocoMotor;
Scene::Scene(std::string nombre) {
	_name = nombre;
	_renderScn = OgreWrapper::OgreManager::GetInstance()->CreateScene(_name);

	// Crear camara
	camera_gObj = AddGameobject("cam");
	camera_gObj->AddComponent("Transform");
	camera_gObj->AddComponent("Camera");

	camera_gObj2 = AddGameobject("cam");
	camera_gObj2->AddComponent("Transform");
	camera_gObj2->AddComponent("Camera");
	//camera_gObj->AddComponent("AudioListener");
	//_currentCam = cam_Obj->AddComponent<LM_Component::Camera>();

	/*SetSceneCam(_renderScn->CreateCamera("ScnCam"));*/
}

Scene::~Scene() {
	std::unordered_map<std::string, GameObject*>::const_iterator it;
	for (it = _gameObjList.cbegin(); it != _gameObjList.end(); it = _gameObjList.erase(it)) {
		delete it->second;
	}
	_renderScn = nullptr;
	_cam = nullptr;
	_nod = nullptr;
}


void Scene::Start() {

	//GameObject* camera = new GameObject();

	for (auto obj : _gameObjList) {
		obj.second->StartComp();
	}

	_isActiveScene = true;
}

void Scene::Update(float dt) {
	//si no esta activa que no haga nada
	if (!_isActiveScene) {
		return;

	}
	for (auto obj : _gameObjList) {

		obj.second->Update(dt);
	}
}
void Scene::Render() {
	_renderScn->Render();
	OgreWrapper::OgreManager::GetInstance()->Render();
}

//?
void Scene::Deactivate() {
	_isActiveScene = false;
}


//Activate

bool Scene::GetActiveStatus() {
	return _isActiveScene;
}

std::string Scene::GetSceneName() {
	return _name;
}

void Scene::SetSceneCam(OgreWrapper::Camera* camera) {
	_cam = camera;
	_renderScn->SetActiveCamera(_cam);
}

GameObject* LocoMotor::Scene::AddGameobject(std::string name) {
	if (_gameObjList.count(name) > 0) {
	#ifdef DEBUG
		std::cerr << "Ya existe un objeto con el nombre " << name << " se retornara" << std::endl;
	#endif // DEBUG
		return _gameObjList[name];	
	}
	OgreWrapper::Node* newNode = _renderScn->CreateNode(name);
	GameObject* newObj = new GameObject(newNode);
	newObj->SetContext(this);
	_gameObjList.insert({ name, newObj });
	return newObj;
}

GameObject* LocoMotor::Scene::GetObjectByName(std::string name) {
	if(_gameObjList.count(name) == 0)
		return nullptr;
	return _gameObjList[name];
}

OgreWrapper::RenderScene* LocoMotor::Scene::GetRender() {
	return _renderScn;
}

GameObject* LocoMotor::Scene::GetCamera() {
	return camera_gObj;
}



