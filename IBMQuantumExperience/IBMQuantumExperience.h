// Copyright by Benjamin Luxbacher
#ifndef _IBMQUANTUMEXPERIENCE_H_
#define _IBMQUANTUMEXPERIENCE_H_

#include <string>
#include <vector>
#include <map>

#include "Config.h"
#include "Request.h"
#include "Qiskit.h"

namespace Qiskit
{
    // The Connector Class to do request to QX Platform
    class IBMQuantumExperience
    {
    public:
        IBMQuantumExperience(std::string token, bool verify = false);
        IBMQuantumExperience(std::string token, Config config, bool verify = false);
        ~IBMQuantumExperience();

        std::vector<std::string> names_backend_ibmqxv2 = { "ibmqx5qv2", "ibmqx2", "qx5qv2", "qx5q", "real" };
        std::vector<std::string> names_backend_ibmqxv3 = { "ibmqx3" };
        std::vector<std::string> names_backend_simulator = { "simulator", "sim_trivial_2", "ibmqx_qasm_simulator", "ibmq_qasm_simulator" };

        std::map<std::string, std::string> RunExperiment();

    private:
        Config config;
        Request req;
    };
}

#endif