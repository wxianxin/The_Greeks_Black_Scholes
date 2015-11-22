//Author: Steven Wang    Date:20151101

#include <iostream>

#include <cmath>

#include "BlackScholes.h"

////CDF of Normal Distribution. Reference: http://www.johndcook.com/blog/cpp_phi/
double BS::phi(double x)
{
	// constants
	double a1 = 0.254829592;
	double a2 = -0.284496736;
	double a3 = 1.421413741;
	double a4 = -1.453152027;
	double a5 = 1.061405429;
	double p = 0.3275911;

	// Save the sign of x
	int sign = 1;
	if (x < 0)
		sign = -1;
	x = fabs(x) / sqrt(2.0);

	double t = 1.0 / (1.0 + p*x);
	double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

	return 0.5*(1.0 + sign*y);
}

double BS::f(double x) {
	return exp(-x*x / 2.0) / sqrt(2.0*3.14159265359);
}

BS::BS(double t, double s, double k, double r, double v, string type) {
	this->t = t;
	this->s = s;
	this->k = k;
	this->r = r;
	this->v = v;
	this->type = type;
}

double BS::ComputePrice() {

	double d1 = (log(s / k) + (r + v*v / 2)*t) / (v*sqrt(t));
	double d2 = d1 - v*sqrt(t);

	if (this->type == "call") {
		return phi(d1)*s - phi(d2)*k*exp(-r*t);
	}

	if (this->type == "put") {
		return phi(-d2)*k*exp(-r*t) - phi(-d1)*s;
	}
}

double BS::ComputeDelta() {
	double d1 = (log(s / k) + (r + v*v / 2)*t) / (v*sqrt(t));
	if (this->type == "call") {
		return phi(d1);
	}

	if (this->type == "put") {
		return phi(d1) - 1;
	}
}

double BS::ComputeVega() {
	double d1 = (log(s / k) + (r + v*v / 2)*t) / (v*sqrt(t));
	return sqrt(t)*s*f(d1);
}

double BS::ComputeTheta() {
	double d1 = (log(s / k) + (r + v*v / 2)*t) / (v*sqrt(t));
	double d2 = d1 - v*sqrt(t);

	if (this->type == "call") {
		return -s*f(d1)*v / 2 / sqrt(t) - r*k*exp(-r*t)*phi(d2);
	}

	if (this->type == "put") {
		return -s*f(d1)*v / 2 / sqrt(t) + r*k*exp(-r*t)*phi(-d2);
	}
}

double BS::ComputeRho() {
	double d1 = (log(s / k) + (r + v*v / 2)*t) / (v*sqrt(t));
	double d2 = d1 - v*sqrt(t);
	if (this->type == "call") {
		return k*t*exp(-r*t)*phi(d2);
	}

	if (this->type == "put") {
		return -k*t*exp(-r*t)*phi(-d2);
	}
}

double BS::ComputeGamma() {
	double d1 = (log(s / k) + (r + v*v / 2)*t) / (v*sqrt(t));
	return f(d1) / (s*v*sqrt(t));
}

string BS::GetType() {
	return this->type;
}





