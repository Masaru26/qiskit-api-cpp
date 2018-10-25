#include <string>
#include <list>
#include "QSimMeasureCreg.h";

class QSimGate{
    public:
        QSimGate();
        QSimGate(std::string, std::string, int, std::list<bool>, QSimMeasureCreg);
        std::string name;
        std::string qasm;
        int position;
        std::list<bool> affectedLines;
        QSimMeasureCreg measureCreg;
};
