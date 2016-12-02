#include<iostream>

using namespace std;

const int HeightMatrix = 3;
const int WidthMatrix = 3;

double A[HeightMatrix][WidthMatrix] = { 0 };//ϵ������
double b[HeightMatrix][1] = { 0 };//ֵ
double D[HeightMatrix][WidthMatrix] = { 0 };//�Խ���
double L[HeightMatrix][WidthMatrix] = { 0 };//������
double U[HeightMatrix][WidthMatrix] = { 0 };//������

//��������
void InitializeA(double initMatrix[HeightMatrix][WidthMatrix + 1]);
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]);
void PrintEquations();
void SplitA();

//�Ծ���A���г�ʼ��
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
//������A��ֳ���������
void SplitA() {
	if (HeightMatrix != WidthMatrix) {
		cout << "�����˴���";
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
//��ӡ����
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]) {
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix; j++) {
			cout << matrix[i][j] << "  \t";
		}
		cout << endl;
	}
}
//��ӡ�����飬���Թ۲�b������
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