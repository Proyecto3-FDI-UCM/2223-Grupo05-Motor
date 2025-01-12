#pragma once
#ifndef LM_AUDIOLISTENER
#define LM_AUDIOLISTENER
#ifdef _MOTORDLL
#define MOTOR_API __declspec(dllexport)
#else
#define MOTOR_API __declspec(dllimport)
#endif
#include "Component.h"
#include "LMVector.h"

namespace FmodWrapper {
	class AudioListener;
}

namespace LocoMotor {
	class MOTOR_API AudioListener : public Component {

	public:
		AudioListener();
		~AudioListener();
		/// @brief Sets the initial position of the listener to the gameobject's
		void PreStart() override;
		/// @brief Inits the component with parameters from lua
		void Init(std::vector<std::pair<std::string, std::string>>& params) override;
		/// @brief Initializes a new instance of the FmodWrapper::AudioListener class.
		void InitComponent() override;
		/// @brief Updates the listener's world attributes to be the same as the gameobject's
		/// @param dt DeltaTime used to calculate the velocity
		void Update(float dt) override;
	private:
		FmodWrapper::AudioListener* _list;
		LMVector3 _lastPos;
	};
};
#endif // !LM_AUDIOLISTENER