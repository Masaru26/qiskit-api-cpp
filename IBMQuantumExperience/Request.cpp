// Copyright by Benjamin Luxbacher
#include "Request.h"

//def __init__(self, token, config = None, verify = True, retries = 5,
//	timeout_interval = 1.0) :
//	self.verify = verify
//	self.client_application = CLIENT_APPLICATION
//	self.config = config
//
//	# Set the proxy information, if present, from the configuration,
//	# with the following format :
//# config = {
//#     'proxies': {
//#         # If using 'urls', assume basic auth or no auth.
//#         'urls': {
//#             'http': 'http://user:password@1.2.3.4:5678',
//#             'https': 'http://user:password@1.2.3.4:5678',
//#         }
//#         # If using 'ntlm', assume NTLM authentication.
//#         'username_ntlm': 'domain\\username',
//#         'password_ntlm': 'password'
//#     }
//# }