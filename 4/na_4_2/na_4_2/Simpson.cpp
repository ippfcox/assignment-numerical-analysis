#include<iostream>
#include<iomanip>

using namespace std;

double f(double x) {
	double y = (pow(x, 4) + cos(x + pow(x, 2)) - log(x)) / (6 * pow(x, 3) + exp(x) + 2);
	return y;
}

void main() {
	double a = 3.0;
	double b = 5.0;
	int iter_count = 10000;
	for (int m = 1; m < iter_count; m++) {
		double h = (b - a) / m;
		double sum1 = 0;
		double sum2 = 0;
		for (int k = 0; k < m; k++) {
			double xk = a + k*h;
			double xk_ = xk + h / 2;
			sum1 += f(xk);
			sum2 += f(xk_);
		}
		double Sm = h / 6 * (f(a) + 2 * sum1 + f(b) + 4 * sum2);
		cout << setprecision(16) << "m = " << m << ", Sm = " << Sm << endl;
	}
	getchar();
}