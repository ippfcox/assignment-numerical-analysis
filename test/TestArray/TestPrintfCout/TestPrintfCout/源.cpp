#include<iostream>
#include<stdio.h>
#include<iomanip>

using namespace std;
/***********************
���ۣ�������������ģ�̫����


***********************/


void main() {
	double a = 0.66666666;
	printf("%.3f\n", a);
	cout << setiosflags(ios::fixed) << setprecision(3) << a;
	getchar();
}