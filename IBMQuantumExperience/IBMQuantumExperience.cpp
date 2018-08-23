// Copyright by Benjamin Luxbacher
#include "IBMQuantumExperience.h"

namespace Qiskit
{
    IBMQuantumExperience::IBMQuantumExperience(std::string token, bool verify = false)
    {
        this->req = Request(token);
    }

    IBMQuantumExperience::IBMQuantumExperience(std::string token, Config config, bool verify = false)
    {
        this->config = config;

        if (!this->config.url.empty())
        {
            std::vector<std::string> url_parsed = split(this->config.url, "/api");

            if (url_parsed.size() == 2)
            {
                std::string hub, group, project;

                std::vector<std::string> project_parsed = split(url_parsed[1], "/Projects/");

                if (project_parsed.size() == 2)
                {
                    project = project_parsed[1];

                    std::vector<std::string> group_parsed = split(project_parsed[0], "/Groups/");

                    if (group_parsed.size() == 2)
                    {
                        group = group_parsed[1];

                        std::vector<std::string> hub_parsed = split(group_parsed[0], "/Hubs/");

                        if (hub_parsed.size() == 2)
                        {
                            hub = hub_parsed[1];
                        }
                    }
                }

                if (!hub.empty() && !group.empty() && !project.empty())
                {
                    this->config.project = project;
                    this->config.group = group;
                    this->config.hub = hub;
                    this->config.url = url_parsed[0] + "/api";
                }
            }
        }

        this->req = Request(token, config, verify);
    }

    IBMQuantumExperience::~IBMQuantumExperience()
    {

    }

    std::map<std::string, std::string> IBMQuantumExperience::RunExperiment()
    {
        /*

        def run_experiment(self, qasm, backend='simulator', shots=1, name=None, seed=None, timeout=60, access_token=None, user_id=None):
            """
            Execute an experiment
            """
            if access_token:
                self.req.credential.set_token(access_token)
            if user_id:
                self.req.credential.set_user_id(user_id)
            if not self.check_credentials():
                raise CredentialsError('credentials invalid')

            backend_type = self._check_backend(backend, 'experiment')
            if not backend_type:
                raise BadBackendError(backend)

            if backend not in self.__names_backend_simulator and seed:
                raise ApiError('seed not allowed for'
                            ' non-simulator backend "{}"'.format(backend))

            name = name or 'Experiment #{:%Y%m%d%H%M%S}'.format(datetime.now())
            qasm = qasm.replace('IBMQASM 2.0;', '').replace('OPENQASM 2.0;', '')
            data = json.dumps({'qasm': qasm, 'codeType': 'QASM2', 'name': name})

            if seed and len(str(seed)) < 11 and str(seed).isdigit():
                params = '&shots={}&seed={}&deviceRunType={}'.format(shots, seed,
                                                                    backend_type)
                execution = self.req.post('/codes/execute', params, data)
            elif seed:
                raise ApiError('invalid seed ({}), seeds can have'
                            ' a maximum length of 10 digits'.format(seed))
            else:
                params = '&shots={}&deviceRunType={}'.format(shots, backend_type)
                execution = self.req.post('/codes/execute', params, data)
            respond = {}
            try:
                status = execution["status"]["id"]
                id_execution = execution["id"]
                result = {}
                respond["status"] = status
                respond["idExecution"] = id_execution
                respond["idCode"] = execution["codeId"]

                if 'infoQueue' in execution:
                    respond['infoQueue'] = execution['infoQueue']

                if status == "DONE":
                    if "result" in execution and "data" in execution["result"]:
                        if "additionalData" in execution["result"]["data"]:
                            ad_aux = execution["result"]["data"]["additionalData"]
                            result["extraInfo"] = ad_aux
                        if execution["result"]["data"].get('p', None):
                            result["measure"] = execution["result"]["data"]["p"]
                        if execution["result"]["data"].get('valsxyz', None):
                            valsxyz = execution["result"]["data"]["valsxyz"]
                            result["bloch"] = valsxyz
                        respond["result"] = result
                        respond.pop('infoQueue', None)

                        return respond
                elif status == "ERROR":
                    respond.pop('infoQueue', None)
                    return respond
                else:
                    if timeout:
                        for _ in range(1, timeout):
                            print("Waiting for results...")
                            result = self.get_result_from_execution(id_execution)
                            if result:
                                respond["status"] = 'DONE'
                                respond["result"] = result
                                respond["calibration"] = result["calibration"]
                                del result["calibration"]
                                respond.pop('infoQueue', None)
                                return respond
                            else:
                                time.sleep(2)
                        return respond
                    else:
                        return respond
            except Exception:
                respond["error"] = execution
                return respond

        */
    }
}