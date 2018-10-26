#include <string>
#include <list>
class QRealDoneFridgeTemperature{
    public:
        QRealDoneFridgeTemperature();
        QRealDoneFridgeTemperature(std::string, std::list<std::string>, std::string);
    
        std::string date;
        std::list<std::string> value;
        std::string unit; 
};
