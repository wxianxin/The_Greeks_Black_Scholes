//Author: Steven Wang    Date:20151101
//Black Scholes, The Greeks, Monto-Carlo simulation

#include <iostream>

#include <string>

#include "BlackScholes.h"

using namespace std;

int main() {

	double s;
	double k;
	double t;
	double r;
	double v;
	string type;

	cout << "Please input info about a call/put option:" << endl;

	cout << "underlying price: " << endl;
	cin >> s;
	
	cout << "strike: " << endl;
	cin >> k;

	cout << "time to maturity: " << endl;
	cin >> t;

	cout << "interest rate: " << endl;
	cin >> r;

	cout << "volatility" << endl;
	cin >> v;

	cout << "option type: " << endl;
	cin >> type;

	BS option(t, s, k, r, v, type);

	cout << "Price: " << option.ComputePrice() << endl;

	cout << "Delta: " << option.ComputeDelta() << endl;

	cout << "Gamma: " << option.ComputeGamma() << endl;

	cout << "Vega:  " << option.ComputeVega() << endl;

	cout << "Rho:   " << option.ComputeRho() << endl;

	cout << "Theta: " << option.ComputeTheta() << endl;

	return 0;
}
