#include<iostream>
#include<math.h>

using namespace std;
/**********************
����˾������ز�������ʼ������ʾ����/�н�������������Ԫ��
����˷���������̲��������ȷ���

1.���þ�����к��еĳ���
2.���ó�ʼ������
3.F5

2016.12.01 14:57
ippfcox
***********************/

const int HeightMatrix = 4;//����
const int WidthMatrix = 5;//����
bool log_flag = false;
double A[HeightMatrix][WidthMatrix] = {0};

void PrintLog(char log[]);
void PrintMatrix();
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]);
void SwapMatrix(int a, int b, char direction);
int ColumnPrimaryElement(int j);

//�����Ϣ
void PrintLog(char log[]){
	if(log_flag){
		cout<<log;
	}
}
//��ʾ��ǰ����
void PrintMatrix(){
	cout<<"--------------------------------------------------"<<endl;
	for(int i = 0; i < HeightMatrix; i++){
		for(int j = 0; j < WidthMatrix; j++){
			cout<<A[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"--------------------------------------------------"<<endl;
}
//��ʼ������
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]){
	for(int i = 0; i < HeightMatrix; i++){
		for(int j = 0; j < WidthMatrix; j++){
			A[i][j] = initMatrix[i][j];
		}
	}
	PrintLog("���󱻳�ʼ��Ϊ\n");
	PrintMatrix();
}
//����������л����У���0��ʼ
void SwapMatrix(int a, int b, char direction){
	switch(direction){
	case 'c':
		//��齻��Խ��
		if(a < 0 || a > WidthMatrix - 1 || b < 0 || b > WidthMatrix - 1 || a == b){
			PrintLog("δ����:��������\n");
			return;
		}
		for(int i = 0; i < HeightMatrix; i++){
			double tmp = A[i][a];
			A[i][a] = A[i][b];
			A[i][b] = tmp;
		}
		PrintLog("��������\n");
		break;
	case 'r':
		if(a < 0 || a > HeightMatrix - 1 || b < 0 || b > HeightMatrix - 1 || a == b){
			PrintLog("δ����:��������\n");
			return;
		}
		for(int j = 0; j < WidthMatrix; j++){
			double tmp = A[a][j];
			A[a][j] = A[b][j];
			A[b][j] = tmp;
		}
		PrintLog("��������\n");
		break;
	default:
		PrintLog("δ����:��־����\n");
		break;
	}
}
//��������Ԫ�أ���Χ[j, MaxHeight]
int ColumnPrimaryElement(int j){
	int max_index = j;
	for(int i = j + 1; i < HeightMatrix; i++){
		if(abs(A[i][j]) > abs(A[max_index][j])){
			max_index = i;
		}
	}
	return max_index;
}

void main(){
	double initMatrix[HeightMatrix][WidthMatrix] = {
		{5.2, -9.5, 1.4, -24.5, 2.8},
		{2.4, 1.7, 16.1, 5.1, -7.3},
		{5.3, 21.3, -4.8, 4.2, -3.1},
		{14.7, 5.7, -1.4, 3.5, 1.5}
	};
	InitializeMatrix(initMatrix);
	for(int j = 0; j < WidthMatrix - 1; j++){
		//��ѡ��Ԫ��
		int a = ColumnPrimaryElement(j);
		cout<<"��"<<j<<"����Ԫ��:|A["<<a<<"]["<<j<<"]| = "<<abs(A[a][j])<<endl;
		//������Ԫ���кͶ�Ӧ��
		SwapMatrix(a, j, 'r');
		cout<<"������Ԫ����"<<a<<"��"<<j<<endl;
		
		//��Ԫ
		for(int i = 0; i < HeightMatrix; i++){
			//ͬһ��û����
			if(i == j){
				continue;
			}
			double coffient = -A[i][j] / A[j][j];
			//cout<<"-"<<A[i][j]<<"/"<<A[j][j]<<"="<<coffient<<endl;
			for(int k = 0; k < WidthMatrix; k++){
				A[i][k] = A[i][k] + coffient * A[j][k];
			}
		}
		PrintMatrix();
	}
	//ȥ����
	for(int i = 0; i < HeightMatrix; i++){
		A[i][WidthMatrix - 1] /= A[i][i];
		A[i][i] = 1;
	}
	cout<<"���վ���:"<<endl;
	PrintMatrix();
	cout<<"������:"<<endl;
	for(int i = 0; i < HeightMatrix; i++){
		cout<<"x"<<i+1<<" = "<<A[i][WidthMatrix - 1]<<endl;
	}
	getchar();
}
