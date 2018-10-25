#include <string>
#include <list>

class QSimDataP{
    public:
        QSimDataP();
        QSimDataP(std::list<int>, std::list<std::string>, std::list<double>);
        std::list<int> qubits;
        std::list<std::string> labels;
        std::list<double> values;
};
