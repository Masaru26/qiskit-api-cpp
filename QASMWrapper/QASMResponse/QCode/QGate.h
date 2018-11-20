#ifndef QGATE_H_INCLUDED__;
#define QGATE_H_INCLUDED__;

#include <string>
#include <list>
#include "QMeasureCreg.h";

class QGate {
	public:
		QGate();
		QGate(std::string, std::string, int, std::list<bool>, QMeasureCreg);
	
		std::string name;
		std::string qasm;
		int position;
		std::list<bool> affectedLines;
		QMeasureCreg measureCreg;
};
#endif