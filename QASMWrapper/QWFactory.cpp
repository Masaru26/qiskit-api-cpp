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
		// Work in progress
		if (jOBJ["paramsCustomize"]["seed"] == Json::nullValue) {
			// RealDone
			QResponse respRD = new QResponseRealDone();
		
			return respRD;
		}
		// Simulation object finished
		else {
			// SIM Done

			// Create lists/objects for jsonqasm
			// GateDefinition List
			string gateD = null;
			for (auto itr : jOBJ["code"]["jsonQASM"]["gateDefinition"]) {
				gateD = itr.asString();
			}

			// Topology
			// Create list with cregs
			std::list<QReg> cregs = new	std::list<QReg>();
			for (auto itr : jOBJ["code"]["jsonQASM"]["topology"]["cregs"]) {
				cregs.insert(new QReg(itr["name"].asString(), itr["size"].asInt32()));
			}
			
			// Create list with qregs
			std::list<QReg> qregs = new	std::list<QReg>();
			for (auto itr : jOBJ["code"]["jsonQASM"]["topology"]["cregs"]) {
				qregs.insert(new QReg(itr["name"].asString(), itr["size"].asInt32()));
			}

			// Create Object
			QTopology topology = new QTopology(cregs, qregs, jOBJ["code"]["jsonQASM"]["topology"]["topology"]["qasmHeader"].asString());

			// Playground List
			std::list<QPlayground> playground = new	std::list<QPlayground>();
			for (auto itr : jOBJ["code"]["jsonQASM"]["playground"]) {
				if (itr["gates"] != Json::nullValue) {
					std::list<QGate> qgates = new std::list<QGate>();
					for (auto gate : itr["gates"]) {
						std::list<bool> affectedLines;
						QMeasureCreg measureCreg;

						if (gate["affectedLines"] != Json::nullValue) {
							affectedLines = new std::list<bool>();
							for (auto lines : gate["affectedLines"]) {
								affectedLines.insert(lines.asBool());
							}
						}
						else {
							affectedLines = NULL;
						}

						if (gate["measureCreg"] != Json::nullValue) {
							measureCreg = new QMeasureCreg(gate["measureCreg"]["line"].asInt32(), gate["measureCreg"]["bit"].asInt32())
						}
						else {
							measureCreg = NULL;
						}
						qgates.insert(new QGate(gate["name"].asString(), gate["qasm"].asString(), gate["position"].asInt32(), affectedLines, measureCreg));
					}
					playground.insert(new QPlayground(itr["name"].asString(), itr["line"].asInt32(), qgates));
				}
				else {
					playground.insert(new QPlayground(itr["name"].asString(), itr["line"].asInt32(), NULL));
				}
			}

			// Create JsonQASM Object
			QJsonQASM jqasm = new QJsonQASM(gateD, topology, playground, jOBJ["code"]["jsonQASM"]["numberGates"].asInt32(), jOBJ["code"]["jsonQASM"]["hasMeasures"].asBool(), jOBJ["code"]["jsonQASM"]["numberColumns"].asInt32(), jOBJ["code"]["jsonQASM"]["include"].asString());

			// Create Simulation Object
			QResponse respSim = new QResponseSim(new QCode(jOBJ["code"]["type"].asString(), jOBJ["code"]["active"].asBool(), jOBJ["code"]["versionId"].asInt32(), jOBJ["code"]["idCode"].asString(), jOBJ["code"]["name"].asString(), jqasm, jOBJ["code"]["qasm"].asString(), jOBJ["code"]["codeType"].asString(), jOBJ["code"]["creationDate"].asString(), jOBJ["code"]["deleted"].asBool(), jOBJ["code"]["orderDate"].asInt64(), jOBJ["code"]["userDeleted"].asBool(), jOBJ["code"]["isPublic"].asBool(), jOBJ["code"]["id"].asString(), jOBJ["code"]["userId"].asString()));
			
			// Return simulation object
			return respSim;
		}

	}
	// Work in progress
	else if (statusID == STATUD_ID_WORKING) {
		// Real UnDone
		QResponse respUndone = new QResponseRealUndone();

		return respUndone;
	}
	else {
		//EXC
		return null
	}
}