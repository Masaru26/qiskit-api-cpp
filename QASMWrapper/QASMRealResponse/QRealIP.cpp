#include "QRealIP.h"

QRealIP::QRealIP(){}

QRealIP::QRealIP(std::string ip, std::string country, std::string continent){
    QRealIP::ip = ip;
    QRealIP::country = country;
    QRealIP::continent = continent;
    
}