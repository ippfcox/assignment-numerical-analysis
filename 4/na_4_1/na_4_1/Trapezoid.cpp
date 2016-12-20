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
	int iter_count = 520;
	for (int n = 500; n < iter_count; n++) {
		double h = (b - a) / n;
		double sum = 0;
		for (int k = 1; k < n; k++) {
			double xk = a + k*h;
			sum += f(xk);
		}
		double Tn = h / 2 * (f(a) + 2 * sum + f(b));
		cout << setprecision(8) << "n = " << n << ", Tn = " << Tn << endl;
	}
	getchar();
}