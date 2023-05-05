#include "LogSystem.h"
#ifdef _DEBUG
#include <iostream>
#endif // _DEBUG
using namespace LocoMotor;
LogSystem* Singleton<LogSystem>::_instance = nullptr;

/**
 * This is the constructor for the LogSystem class which initializes the _file pointer to nullptr.
 */
LogSystem::LogSystem() {
	//Init();
	//Create ();
	_file = nullptr;
}

LogSystem::~LogSystem() {
	FileClose();
}

/**
 * The function initializes the log system by opening a file named "log.txt" in write mode.
 */
void LogSystem::Initialize() {

	if (_file == nullptr)
		fopen_s(&_file, "log.txt", "w+");
}

/**
 * The function closes a file in the LogSystem.
 */
void LogSystem::FileClose() {
	if (_file != nullptr)
		fclose(_file);
}


/**
 * The function saves different types of messages to a log file.
 * @brief Saves different types of messages to a log file.
 * @param type An integer representing the type of message being logged. Messages of type 0 are errors,
 * messages of type 1 are warnings, and messages of type greater than 1 are other types of messages.
 * @param message A string containing the message to be logged.
 */
void LogSystem::Save(int type, std::string message) {
	// Mensajes de error->0
	// Mensajes de aviso->1
	// Otros mensajes -> >1

	if (_file == nullptr)
		fopen_s(&_file, "log.txt", "w+");

	std::string strToLog = "";
	if (type == 0) {
		strToLog = "Error: " + message + "\n";
		fprintf(_file, strToLog.c_str());
	}
	else if (type == 1) {
		strToLog = "Warning: " + message + "\n";
		fprintf(_file, strToLog.c_str());
	}

	else if (type > 1) {
		strToLog = message + "\n";
		fprintf(_file, strToLog.c_str());
	}

#ifdef _DEBUG
	std::cout << strToLog << "\n";
#endif // _DEBUG

}

