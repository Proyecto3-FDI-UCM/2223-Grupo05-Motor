﻿#include "SceneManager.h"
#include <SDL.h>

#include "ComponentsFactory.h"
#include "OgreManager.h"

using namespace LocoMotor;

/* Initializing the static member variable `_instance` of the `Singleton` template class with a null
pointer value. This variable is used to store the single instance of the `SceneManager` class that
is created and accessed through the `GetInstance()` method of the `Singleton` template class. */
SceneManager* Singleton<SceneManager>::_instance = nullptr;

/**
 * This is the constructor for the SceneManager class, initializing its member variables.
 */
SceneManager::SceneManager() {
	_activeScene = nullptr;
	_actTime = 0;
	_lastTime = 0;
	_deltaTime = 0.1f;
}

/**
 * The destructor of the SceneManager class that deletes all scenes stored in a map.
 */
SceneManager::~SceneManager() {
	std::map<std::string, Scene*>::const_iterator it;
	for (it = _sceneInfo.cbegin(); it != _sceneInfo.cend(); it = _sceneInfo.erase(it)) {
		delete it->second;
	}
}


Scene* SceneManager::CreateScene(std::string name) {
	std::map<std::string, Scene*>::iterator it = _sceneInfo.find(name);
	if (it == _sceneInfo.end()) {

		Scene* newScene = new Scene(name);


		_sceneInfo.insert({ name, newScene });

		if (_activeScene == nullptr) {
			_activeScene = newScene;
		
		}

		return newScene;
	}

	else {


		//si devuelve nullptr mandar mensaje al logSystem
		return nullptr;
	}

}


Scene* SceneManager::ChangeScene(std::string name) {
	std::map<std::string, Scene*>::iterator it = _sceneInfo.find(name);
	OgreWrapper::OgreManager* renderMan = OgreWrapper::OgreManager::GetInstance();

	if (it != _sceneInfo.end()) {
		//si hay alguna escena activa, se desactiva
		if (_activeScene != nullptr && _activeScene != it->second) {

			_activeScene->DeActivate();
		}


		StartScene(it->second);
		renderMan->SetActiveScene(renderMan->GetScene(it->second->GetSceneName()));
		_activeScene = it->second;
		return it->second;
		//return "Cambiada la escena";


	}
	else {
		//Mensaje a logsystem

		return nullptr;
		//return "No existe la escena" + name;
	}

}



Scene* SceneManager::GetSceneByName(std::string name) {

	std::map<std::string, Scene*>::iterator it = _sceneInfo.find(name);
	if (it != _sceneInfo.end()) {

		return it->second;
	}
	else {
		return nullptr;
	}

}


Scene* LocoMotor::SceneManager::GetCurrentScene()
{
	return _activeScene;
}


void LocoMotor::SceneManager::Update() {

	_actTime = SDL_GetTicks();
	_deltaTime = (float)_actTime - (float)_lastTime;
	_lastTime = _actTime;

	if (_deltaTime <= 0) _deltaTime = 0.001f;

	Scene* sc = _activeScene;
	if (_activeScene != nullptr) {
		sc->Update(_deltaTime); 
		sc->Render();
	}
	if (sc!=nullptr && sc->ToDestroy()) {
		sc->Destroy();
	}
}


float LocoMotor::SceneManager::GetDelta() {
	return _deltaTime;
}


void SceneManager::StartScene(Scene* scn) {
	scn->Start();
}