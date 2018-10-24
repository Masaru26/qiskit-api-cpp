// Copyright by Benjamin Luxbacher

#ifndef _QBACKEND_H_
#define _QBACKEND_H_

#include <stdio.h>
#include <string>
#include <list>

namespace QRest
{
    namespace QAvailableBackends
    {
        class Couple
        {
        public:
            Couple(int control, int target);

            int control;
            int target;
        };

        class QBackend
        {
        private:

        public:
            QBackend();
            QBackend(std::string id, std::string name);
            QBackend(
                std::string name, 
                std::string version, 
                std::string status, 
                std::string serialNumber, 
                std::string description, 
                std::string basisGates, 
                std::string onlineDate, 
                std::string chipName, 
                bool deleted, 
                std::string id, 
                std::string topologyId, 
                std::string url, 
                std::string internalId, 
                bool simulator, 
                bool allowQObject, 
                int nQubits, 
                std::list<Couple> couplingMap
            );
            ~QBackend();
            
            std::string name;
            std::string version;
            std::string status;
            std::string serialNumber;
            std::string description;
            std::string basisGates;
            std::string onlineDate;
            std::string chipName;
            bool deleted;
            std::string id;
            std::string topologyId;
            std::string url;
            std::string internalId;
            bool simulator;
            bool allowQObject;
            int nQubits;
            std::list<Couple> couplingMap;
        };
    }
}

#endif