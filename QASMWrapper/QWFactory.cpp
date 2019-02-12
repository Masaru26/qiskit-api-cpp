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
			#pragma region ResponseReal
			// RealDone
			#pragma region Result
			// Results
			std::list<std::string> labels = new	std::list<std::string>();
			for (auto itr : jOBJ["result"]["data"]["p"]["labels"]) {
				labels.insert(itr.asString());
			}

			std::list<double> values = new	std::list<double>();
			for (auto itr : jOBJ["result"]["data"]["p"]["values"]) {
				labels.insert(itr.asDouble);
			}

			QDataP dataP = new QDataP(labels, values);
			QData data = new QData(dataP, jOBJ["result"]["data"]["qasm"], jOBJ["result"]["data"]["serialNumberDevice"].asString(), jOBJ["result"]["data"]["time"].asDOuble());
			QResult result = new QResult(jOBJ["result"]["date"].asString(), data);
			#pragma endregion

			#pragma region Calibration
			// Calibration
			#pragma region QFridgeParams
			// QFridgeParameters
			std::list<std::string> tempvalue = new std::list<std::string>();
			if (jOBJ["calibration"]["fridgeParameters"]["Temperature"] != Json::nullValue) {
				for (auto itr : jOBJ["calibration"]["fridgeParameters"]["Temperature"]["value"])
				{
					tempvalue.insert(itr.asString());
				}
			}
			
			QFridgeTemperature temp = new QFridgeTemperature(jOBJ["calibration"]["fridgeParameters"]["Temperature"]["date"].asString(), tempvalue, jOBJ["calibration"]["fridgeParameters"]["Temperature"]["unit"].asString());

			QFridgeParameters fridgeparams = new QFridgeParameters(jOBJ["calibration"]["cooldownDate"].asString(), );
			#pragma endregion

			#pragma region QubitList
			// Qubit list
			std::list<QQubit> qubits = new std::list<QQubit>();

			for (auto itr : jOBJ["calibration"]["qubits"]) {
				qubits.insert(
					new QQubit(itr["name"].asString()
						, new QQubitContent(
							itr["buffer"]["date"].asString()
							, itr["buffer"]["value"].asDouble()
							, itr["buffer"]["unit"].asString()
						)
						, new QQubitContent(
							itr["gateTime"]["date"].asString()
							, itr["gateTime"]["value"].asDouble()
							, itr["gateTime"]["unit"].asString())
					)
					, new QQubitContent(
						itr["T2"]["date"].asString()
						, itr["T2"]["value"].asDouble()
						, itr["T2"]["unit"].asString()
					)
					, new QQubitContent(
						itr["T1"]["date"].asString()
						, itr["T1"]["value"].asDouble()
						, itr["T1"]["unit"].asString()
					)
					, new QQubitContent(
						itr["frequency"]["date"].asString()
						, itr["frequency"]["value"].asDouble()
						, itr["frequency"]["unit"].asString()
					)
					, new QQubitContent(
						itr["gateError"]["date"].asString()
						, itr["gateError"]["value"].asDouble()
					)
					, new QQubitContent(
						itr["readoutError"]["date"].asString()
						, itr["readoutError"]["value"].asDouble()
					)
				);
			}

			// MultiQubitGates list
			std::list<QMultiQubitGates> qubitGates = new std::list<QMultiQubitGates>();

			for (auto itr : jOBJ["calibration"]["multiQubitGates"]) {
				std::list<int> qus = new std::list<int>();
				for (auto qu : itr["qubits"]) {
					qus.insert(qu.asInt32());
				}

				qubitGates.insert(new QMultiQubitGates(qus, itr["type"].asString(), new QGateError(itr["gateError"]["date"].asString(), itr["gatError"]["value"].asDouble()), itr["name"].asString()));
			}
			#pragma endregion

			// Create calibration object
			QCalibration calibration = new QCalibration(jOBJ["calibration"]["lastUpdateDate"].asString(), frideparams, qubits, qubitGates, jOBJ["calibration"]["version"].asString());
			#pragma endregion

			// Create response object
			QResponse respRD = new QResponseRealDone(
				jOBJ["startDate"].asString()
				, jOBJ["modificationDate"].asString()
				, jOBJ["shots"].asInt32()
				, jOBJ["deleted"].asBool()
				, jOBJ["userDeleted"].asBool()
				, jOBJ["userId"].asString()
				, jOBJ["jobId"].asString()
				, jOBJ["qasm"].asString()
				, jOBJ["endDate"].asString()
				, jOBJ["id"].asString()
				, jOBJ["deviceId"].asString()
				, result
				, new QStatus(
					jOBJ["status"]["id"].asString()
				)
				, new QIP(
					jOBJ["ip"]["ip"].asString()
					, jOBJ["ip"]["status"].asString()
					, jOBJ["ip"]["continent"].asString()
				)
				, calibration
				, jOBJ["typeCredits"].asString()
				, jOBJ["time"].asDouble()
			);
			#pragma endregion
			return respRD;
		}
		else {
			#pragma region ResponseSimulation
			// SIM Done
			#pragma region jsonqasm objects


			// Create lists/objects for jsonqasm
			// GateDefinition List
			string gateD = null;
			for (auto itr : jOBJ["code"]["jsonQASM"]["gateDefinition"]) {
				gateD = itr.asString();
			}

			#pragma region Topology
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
			QTopology topology = new QTopology(
				cregs
				, qregs
				, jOBJ["code"]["jsonQASM"]["topology"]["topology"]["qasmHeader"].asString()
			);
			#pragma endregion
			#pragma region Playground
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
			#pragma endregion

			// Create JsonQASM Object
			QJsonQASM jqasm = new QJsonQASM(
				gateD
				, topology
				, playground
				, jOBJ["code"]["jsonQASM"]["numberGates"].asInt32()
				, jOBJ["code"]["jsonQASM"]["hasMeasures"].asBool()
				, jOBJ["code"]["jsonQASM"]["numberColumns"].asInt32()
				, jOBJ["code"]["jsonQASM"]["include"].asString()
			);

			#pragma endregion
			#pragma region Result
			#pragma region CreateDataPLists

			// Qubit list
			std::list<int> resQubit = new std::list<int>();
			for (auto itr : jOBJ["result"]["data"]["p"]["qubits"]) {
				resQubit.insert(itr.asInt32());
			}
			
			// Get label list
			std::list<std::string> resLabel = new std::list<std::string>();
			for (auto itr : jOBJ["result"]["data"]["labels"]) {
				resLabel.insert(itr.asString());
			}

			// Get value list
			std::list<double> resValues = new std::list<double>();
			for (auto itr : jOBJ["result"]["data"]["values"]) {
				resValues.insert(itr.asDouble());
			}

			#pragma endregion

			QDataP datap = new QDataP(resQubit, resLabel, resValues);
			QData data = new QData(
				jOBJ["result"]["data"]["creg_labels"].asString()
				, datap
				, new QAdditionalData(
					jOBJ["result"]["data"]["additionalData"]["seed"].asString()
				)
				, jOBJ["result"]["data"]["qasm"].asString()
				, jOBJ["result"]["data"]["serialNumberDevice"].asString()
				, jOBJ["result"]["data"]["time"].asDouble()
			);

			QResult result = new QResult(jOBJ["result"]["date"].asString(), data);
			#pragma endregion

			// Create Simulation Object
			QResponse respSim = new QResponseSim(
				new QCode(
					jOBJ["code"]["type"].asString()
					, jOBJ["code"]["active"].asBool()
					, jOBJ["code"]["versionId"].asInt32()
					, jOBJ["code"]["idCode"].asString()
					, jOBJ["code"]["name"].asString()
					, jqasm
					, jOBJ["code"]["qasm"].asString()
					, jOBJ["code"]["codeType"].asString()
					, jOBJ["code"]["creationDate"].asString()
					, jOBJ["code"]["deleted"].asBool()
					, jOBJ["code"]["orderDate"].asInt64()
					, jOBJ["code"]["userDeleted"].asBool()
					, jOBJ["code"]["isPublic"].asBool()
					, jOBJ["code"]["id"].asString()
					, jOBJ["code"]["userId"].asString()
				)
				, new QParamsCustomize(
					jOBJ["paramsCustomize"]["seed"].asInt64()
				)
				, jOBJ["time"].asDouble() // Könnte mit der länge eng werden hat 16 Nachkommastellen
				, jOBJ["deviceRunType"].asString()
				, jOBJ["startDate"].asString()
				, jOBJ["modificationDate"].asInt64()
				, jOBJ["shots"].asInt32()
				, jOBJ["deleted"].asBool()
				, jOBJ["userDeleted"].asBool()
				, jOBJ["userId"].asString()
				, jOBJ["qasm"].asString()
				, jOBJ["endDate"].asString()
				, jOBJ["id"].asString()
				, jOBJ["deviceId"].asString()
				, jOBJ["codeId"].asString()
				, result
				, new QStatus(
					jOBJ["status"]["id"].asString()
				)
				, new QIP(
					jOBJ["ip"]["ip"].asString()
					, jOBJ["ip"]["country"].asString()
					, jOBJ["ip"]["continent"].asString()
				)
			);
			#pragma endregion
			// Return simulation object
			return respSim;
		}
	}
	else if (statusID == STATUD_ID_WORKING) {
		#pragma region ResponseUndone
		// Real Undone
		QResponse respUndone = new QResponseRealUndone(
			jOBJ["startDate"].asString()
			, jOBJ["modificationDate"].asInt64()
			, jOBJ["shots"].asInt32
			, jOBJ["deleted"].asBool()
			, jOBJ["userDeleted"].asBool()
			, jOBJ["userId"].asString()
			, jOBJ["jobId"].asString()
			, jOBJ["qasm"].asString()
			, jOBJ["id"].asString()
			, new QStatus(
				jOBJ["status"]["id"].asString()
			)
			, new QIP(
				jOBJ["ip"]["ip"].asString()
				, jOBJ["ip"]["country"].asString()
				, jOBJ["ip"]["continent"].asString()
			)
			, jOBJ["typeCredits"].asString()
		);
		#pragma endregion
		return respUndone;
	}
	else {
		//EXC or something else
		return null
	}
}