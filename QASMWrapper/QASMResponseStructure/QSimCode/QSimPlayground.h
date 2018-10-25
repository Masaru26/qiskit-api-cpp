#include <string>
#include <list>
#include "QSimGate.h";

class QSimPlayground{
    public:
        QSimPlayground();
        QSimPlayground(std::string, int, std::list<QSimGate>);
        std::string name;
        int line;
        std::list<QSimGate> gates;
};
