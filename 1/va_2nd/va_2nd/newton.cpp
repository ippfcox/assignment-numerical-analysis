#include<stdio.h>
#include<math.h>

double f(double x){
	double y = 1 - x - sin(x);
	return y;
}
double f_derivative(double x){
	double y_derivative = -1 - cos(x);
	return y_derivative;
}
double get_next_xk(double xk){
	double next_xk = xk - f(xk)/f_derivative(xk);
	return next_xk;
}
void main(){
	double xk = 0.1;
	double next_xk = 0.0;
	int n = 20;
	int i = 0;
	for(i = 0; i< n; i++){
		next_xk = get_next_xk(xk);
		printf("No.%d:xk = %.10lf\n", i + 1, next_xk);
		xk = next_xk;
	}
	getchar();
}
