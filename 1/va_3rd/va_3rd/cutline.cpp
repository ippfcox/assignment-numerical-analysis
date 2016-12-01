#include<stdio.h>
#include<math.h>

double f(double x){
	double y = 1 - x - sin(x);
	return y;
}
double get_next_xk(double previous_xk, double xk){
	double next_xk = xk - ((xk - previous_xk)*f(xk))/(f(xk) - f(previous_xk));
	return next_xk;
}
void main(){
	double previous_xk = 0.0;
	double xk = 1.0;

	int n = 20;
	int i = 0;
	for(i = 0; i < n; i++){
		double next_xk = get_next_xk(previous_xk, xk);
		previous_xk = xk;
		xk = next_xk;
		printf("No.%d:xk = %.10lf\n", i + 1, xk);
	}
	getchar();
}