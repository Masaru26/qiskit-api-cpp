#include "QWFactory.h"

QResponse QWFactory::Create(std::string str)
{
	Json::Reader jr;
	Json::Value jObj;
	jr.parse(str, jObj);
	
	// Schauen welche Art von Response
	// check if done status-->ID
	std::string statusID = jOBJ["status"]["id"].asString();

	if (statusID == STATUD_ID_DONE) {

		// wenn paramscustomize seed vorhanden --> SIM
		if (jOBJ["paramsCustomize"]["seed"] == Json::nullValue) {
			// RealDone
			QResponseRealDone respRD = new QResponseRealDone(); // Konstruktor ist falsch
		}
		else {
			// SIM Done
			QResponseSim respSim = new QResponseSim(); // Konstruktor könnt passen
		}

	}
	else if (statusID == STATUD_ID_WORKING) {
		// Real UnDone
	}
	else {
		//EXC
	}


	return QResponse();
}