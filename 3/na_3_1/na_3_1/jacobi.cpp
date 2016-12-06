#include<iostream>

using namespace std;

const int HeightMatrix = 3;
const int WidthMatrix = 3;

double A[HeightMatrix][WidthMatrix] = { 0 };
double b[HeightMatrix] = { 0 };
double x[HeightMatrix] = { 0 };
double x_old[HeightMatrix] = { 0 };

void Initialize(double tmpA[HeightMatrix][WidthMatrix], double tmpb[HeightMatrix]) {
	for (int i = 0; i < HeightMatrix; i++) {
		b[i] = tmpb[i];
		for (int j = 0; j < WidthMatrix; j++) {
			A[i][j] = tmpA[i][j];
		}
	}
}
void BackupX() {
	for (int i = 0; i < HeightMatrix; i++) {
		x_old[i] = x[i];
	}
}
void PrintSolution() {
	cout << "--------------------" << endl;
	for (int i = 0; i < HeightMatrix; i++) {
		cout << "x" << i + 1 << " = " << x[i] << endl;
	}
	cout << "--------------------" << endl;
}

void main() {
	/*double tmpA[HeightMatrix][WidthMatrix] = {
	{ 4, -1, 0 },
	{ -1, 4, -1 },
	{ 0, -1, 4 }
	};*/
	double tmpA[HeightMatrix][WidthMatrix] = {
		{ 1.4, 23.9, 12.4 },
		{3.1, -2.8, 8.3 },
		{13.8, 2.6, -3.4 }
	};

	//double tmpb[HeightMatrix] = { 2, 6, 2 };
	double tmpb[HeightMatrix] = { 15.9, 8.3, 29.1 };
	Initialize(tmpA, tmpb);
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
			x[j] = 1 / A[j][j] * (b[j] - sigma1 - sigma2);
		}
		PrintSolution();
		BackupX();
	}
	getchar();
}