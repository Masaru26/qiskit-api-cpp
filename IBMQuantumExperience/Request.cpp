// Copyright by Benjamin Luxbacher
#include "Request.h"

namespace Qiskit
{
    // The Request class to manage the methods
    Request::Request(std::string token, Config config, bool verify, int retries, double timeout_interval)
    {
        this->verify = verify;
        this->client_application = CLIENT_APPLICATION;
        this->config = config;
        this->errorsNotRetry = { 401, 403, 413 };

        // Set the proxy information, if present, from the configuration,
        // with the following format:
        // config = {
        //     'proxies': {
        //         # If using 'urls', assume basic auth or no auth.
        //         'urls': {
        //             'http': 'http://user:password@1.2.3.4:5678',
        //             'https': 'http://user:password@1.2.3.4:5678',
        //         }
        //         # If using 'ntlm', assume NTLM authentication.
        //         'username_ntlm': 'domain\\username',
        //         'password_ntlm': 'password'
        //     }
        // }

        // Set the basic proxy settings, if present. 
        this->proxy_urls = std::map<std::string, std::string>();
        this->ntlm_credentials = std::map<std::string, std::string>();

        if (!config.proxies.empty())
        {
            if (config.proxies.count("http") != 0 && config.proxies.count("https") != 0)
            {
                this->proxy_urls["http"] = config.proxies["http"];
                this->proxy_urls["https"] = config.proxies["https"];
            }

            if (config.proxies.count("username_ntlm") != 0 && config.proxies.count("password_ntlm") != 0)
            {
                this->ntlm_credentials["username"] = this->config.proxies["username_ntlm"];
                this->ntlm_credentials["password"] = this->config.proxies["password_ntlm"];
            }
        }

        // Set the extra arguments to requests (proxy and auth).

        /*
        ToDo:
        # Set the extra arguments to requests (proxy and auth).
        self.extra_args = {}
        if self.proxy_urls:
            self.extra_args['proxies'] = self.proxy_urls
        if self.ntlm_credentials:
            self.extra_args['auth'] = HttpNtlmAuth(
                self.ntlm_credentials['username'],
                self.ntlm_credentials['password'])
        */

       if (!this->config.client_application.empty())
       {
           this->client_application += (":" + this->config.client_application);
       }

       this->credential = Credentials(token, this->config, verify, this->proxy_urls, this->ntlm_credentials);

       this->retries = retries;
       this->timeout_interval = timeout_interval;
       this->result = NULL;

       

        /*
        ToDo:

        if not isinstance(retries, int):
            raise TypeError('post retries must be positive integer')
        self.retries = retries
        self.timeout_interval = timeout_interval
        self.result = None
        self._max_qubit_error_re = re.compile(
            r".*registers exceed the number of qubits, "
r"it can\'t be greater than (\d+).*")
        */
    }

    Request::~Request()
    {

    }

    // Check is the user's token is valid
    bool Request::CheckToken(int status_code)
    {

    }

    // POST Method Wrapper of the REST API
    std::map<std::string, std::string> Request::Post(std::string path, std::string params, std::string data)
    {

    }

    // PUT Method Wrapper of the REST API
    std::map<std::string, std::string> Request::Put(std::string path, std::string params, std::string data)
    {

    }

    // GET Method Wrapper of the REST API
    std::map<std::string, std::string> Request::Get(std::string path, std::string params, bool with_token)
    {

    }

    // check response
    // @param: std::string respond: HTTP response.
    // @return: bool: true if the response is good, else false.
    // @raises: ApiError: response isn't formatted properly.
    bool Request::ResponseGood(HTTPResponse respond)
    {

    }

    // parse text of response for HTTP errors
    /*
        This parses the text of the response to decide whether to
        retry request or raise exception. At the moment this only
        detects an exception condition.
    */
    // @param: Response respond: requests.Response object
    // @return: bool: false if the request should be retried, true if not.
    // @raises: RegisterSizeError
    bool Request::ParseResponse(HTTPResponse respond)
    {

    }
}
