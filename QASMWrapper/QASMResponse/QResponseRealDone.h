#ifndef QRESPONSEREALDONE_H_INCLUDED__;
#define QRESPONSEREALDONE_H_INCLUDED__;

class QResponseRealDone : public QResponseReal {
	public:
		QResponseRealDone();
		QResponseRealDone(double);
		double time;
};

#endif