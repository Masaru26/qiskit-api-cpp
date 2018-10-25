#include <string>
#include "QSimJsonQASM.h";

class QSimCode{
    public:
        QSimCode();
        QSimCode(std::string, bool, int, std::string, std::string, QSimJsonQASM, std::string, std::string, std::string, bool, long, bool, bool, std::string, std::string);
        std::string type;
        bool active;
        int versionId;
        std::string idCode;
        std::string name;
        QSimJsonQASM jsonQASM;
        std::string qasm;
        std::string codeType;
        std::string creationDate;
        bool deleted;
        long orderDate;
        bool userDeleted;
        bool isPublic;
        std::string id;
        std::string userId;
};
