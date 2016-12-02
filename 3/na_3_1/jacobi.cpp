#include<iostream>

using namespace std;

const int HeightMatrix = 3;
const int WidthMatrix = 3;

double A[HeightMatrix][WidthMatrix] = { 0 };//系数矩阵
double b[HeightMatrix][1] = { 0 };//值
double D[HeightMatrix][WidthMatrix] = { 0 };//对角阵
double L[HeightMatrix][WidthMatrix] = { 0 };//下三角
double U[HeightMatrix][WidthMatrix] = { 0 };//上三角

//函数声明
void InitializeA(double initMatrix[HeightMatrix][WidthMatrix + 1]);
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]);
void PrintEquations();
void SplitA();

//对矩阵A进行初始化
void InitializeA(double initMatrix[HeightMatrix][WidthMatrix + 1]) {
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix + 1; j++) {
			if (j == WidthMatrix) {
				b[i][0] = initMatrix[i][j];
				continue;
			}
			A[i][j] = initMatrix[i][j];
		}
	}
}
//将矩阵A拆分成三个矩阵
void SplitA() {
	if (HeightMatrix != WidthMatrix) {
		cout << "发生了错误";
		return;
	}
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix; j++) {
			if (i < j) {
				U[i][j] = A[i][j];
			}
			if (i > j) {
				L[i][j] = A[i][j];
			}
			if (i == j) {
				D[i][j] = A[i][j];
			}
		}
	}
}
//打印矩阵
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]) {
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix; j++) {
			cout << matrix[i][j] << "  \t";
		}
		cout << endl;
	}
}
//打印方程组，用以观察b的内容
void PrintEquations() {
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix + 1; j++) {
			if (j == WidthMatrix) {
				cout << " " << b[i][0];
				continue;
			}
			if (j == WidthMatrix - 1) {
				cout << " " << A[i][j] << "x" << j + 1 << " =";
				continue;
			}
			cout << " " << A[i][j] << "x" << j + 1 << " +";
		}
		cout << endl;
	}
}
void main() {
	double tmpA_b[HeightMatrix][WidthMatrix + 1] = {
		{1.4, 23.9, 12.4, 15.9},
		{3.1, -2.8, 8.3, 8.3},
		{13.8, 2.6, -3.4, 29.1}
	};
	InitializeA(tmpA_b);
	SplitA();
	/*PrintMatrix(A);
	PrintMatrix(D);
	PrintMatrix(L);
	PrintMatrix(U);*/
	PrintEquations();
	getchar();
}