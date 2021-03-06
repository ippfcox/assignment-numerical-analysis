/************************
Jacobi迭代，手动设置了矩阵的状态，
调整为直接就是列选主元素的状态，
感觉我这程序更好一些啊

注意#include<iomanip>
cout << setprecision(4) << x[i] << endl;
以及这次没有用到的setiosflags(ios::fixed);

2016.12.01 11:58
ippfcox@717
************************/

#include<iostream>
#include<iomanip>

using namespace std;

const int HeightMatrix = 3;
const int WidthMatrix = 3;

double A[HeightMatrix][WidthMatrix] = { 0 };
double b[HeightMatrix] = { 0 };
double x[HeightMatrix] = { 0 };
double x_old[HeightMatrix] = { 0 };

//初始化矩阵A和列向量b
void Initialize(double tmpA[HeightMatrix][WidthMatrix], double tmpb[HeightMatrix]) {
	for (int i = 0; i < HeightMatrix; i++) {
		b[i] = tmpb[i];
		for (int j = 0; j < WidthMatrix; j++) {
			A[i][j] = tmpA[i][j];
		}
	}
}
//旧值传新值
void BackupX() {
	for (int i = 0; i < HeightMatrix; i++) {
		x_old[i] = x[i];
	}
}
void PrintSolution(int i) {
	cout << "--------------------" << endl;
	cout << "No." << i << endl;
	for (int i = 0; i < HeightMatrix; i++) {
		cout << "x" << i + 1 << " = ";
		cout << setprecision(4) << x[i] << endl;
	}
	cout << "--------------------" << endl;
}
void PrintMatrix() {
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix; j++) {
			cout << A[i][j] << "\t";
		}
		cout << "|" << b[i] << endl;
	}
}
void main() {

	double tmpA[HeightMatrix][WidthMatrix] = {
		{13.8, 2.6, -3.4 },
		{1.4, 23.9, 12.4 },
		{3.1, -2.8, 8.3 }
	};
	double tmpb[HeightMatrix] = { 29.1, 15.9, 8.3 };
	Initialize(tmpA, tmpb); PrintMatrix();
	int iterationCount = 20;
	for (int i = 0; i < iterationCount; i++) {
		for (int j = 0; j < HeightMatrix; j++) {
			double sigma1 = 0, sigma2 = 0;
			for (int m = 0; m < WidthMatrix; m++) {
				if (m == j) {
					continue;
				}
				if (m < j) {
					sigma1 += A[j][m] * x_old[m];
				}
				if (m > j) {
					sigma2 += A[j][m] * x_old[m];
				}
			}
			x[j] = (b[j] - sigma1 - sigma2) / A[j][j];
		}
		PrintSolution(i+1);
		BackupX();
	}
	getchar();
}