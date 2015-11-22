//Author: Steven Wang    Date:20151101
#ifndef BLACKSCHOLES_H_
#define BLACKSCHOLES_H_

using namespace std;

class BS {
private:
	double t;
	double s;
	double k;
	double r;
	double v;
	string type;

public:
	
	double phi(double x);

	double f(double x);

	BS(double t, double s, double k, double r, double v, string type);

	double ComputePrice();

	double ComputeDelta();

	double ComputeVega();

	double ComputeTheta();

	double ComputeRho();

	double ComputeGamma();

	string GetType();


};

#endif