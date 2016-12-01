#include<stdio.h>
#include<math.h>

double f(double x);

void main(){
	double epsilon = 0.000000005;
	double a = 0.0;
	double b = 1.0;
	double c = 0.0;
	int n = (int)(log((b-a)/epsilon)/log(2.0)) + 1;
	printf("共需要运算%d次\n", n);
	int i = 0;
	for(i = 0; i < n+5; i++){
		c = (a+b)/2.0;
		
		printf("No.%d\na = %.10lf\nb = %.10lf\nc = %.10lf\n---\n", i + 1, a, b, c);

		if(f(a) * f(c) < 0)
			b = c;
		else
			a = c;
	}
	printf("%.10lf", c);
	getchar();
}
double f(double x){
	double y = 1 - x - sin(x);
	return y;
}