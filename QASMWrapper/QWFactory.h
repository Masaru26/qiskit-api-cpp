#ifndef QWFACTORY_CPP_INCLUDED
#define QWFACTORY_CPP_INCLUDED

#include "QASMResponse\QResponse.h"
#include "QASMResponse\QResponseRealUndone.h"
#include "QASMResponse\QResponseRealDone.h"
#include "QASMResponse\QResponseSim.h"
#include <jsoncpp/json/json.h>
#include <string>

#define STATUD_ID_DONE "DONE"
#define STATUD_ID_WORKING "WORKING_IN_PROGRESS"

static class QWFactory {

public:
	QResponse Create(std::string);
	
};

#endif