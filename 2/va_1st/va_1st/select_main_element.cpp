#include<iostream>
#include<math.h>

using namespace std;
/**********************
����˾������ز�������ʼ������ʾ����/�н�����������/�����ֵ
2016.11.30 20:03
ippfcox
***********************/

const int HeightMatrix = 4;//����
const int WidthMatrix = 5;//����
bool log_flag = true;
double A[HeightMatrix][WidthMatrix] = {0};

void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]);
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]);
void PrintLog(char log[]);
void SwapMatrix(int a, int b, char direction);
int ColumnPrimaryElement(int j);
int MaxArray(int a, char direction);
void Test();

//�����Ϣ
void PrintLog(char log[]){
	if(log_flag){
		cout<<log;
		//PrintMatrix(A);
	}
}
//��ʾ��ǰ����,���м��޸�
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]){
	for(int i = 0; i < HeightMatrix; i++){
		for(int j = 0; j < WidthMatrix; j++){
			cout<<matrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
//�úܱ��ķ�����ʼ������
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]){
	for(int i = 0; i < HeightMatrix; i++){
		for(int j = 0; j < WidthMatrix; j++){
			A[i][j] = initMatrix[i][j];
		}
	}
	PrintLog("���󱻳�ʼ��Ϊ\n");
	PrintMatrix(A);
}
//����������л����У���ͷΪ0������
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
//û�б�Ҫ���������ֵ������Ԫ��Ҳ�����������в���[j, MaxHeight]
int ColumnPrimaryElement(int j){
	int max_index = j;
	for(int i = j + 1; i < HeightMatrix; i++){
		if(abs(A[i][j]) > abs(A[max_index][j])){
			max_index = i;
		}
	}
	return max_index;
}
//����ĳ��/�еľ���ֵ���ֵ����������
int MaxArray(int a, char direction){
	int max_index = 0;
	switch(direction){
	case 'c':
		if(a < 0 || a > WidthMatrix - 1){
			PrintLog("δ�ҵ����ֵ:��������\n");
			return -1;
		}
		for(int i = 1; i < HeightMatrix; i++){
			if(abs(A[i][a]) > abs(A[max_index][a])){
				max_index= i;
			}
		}
		PrintLog("�ҵ��������ֵ\n");
		break;
	case 'r':
		if(a < 0 || a > HeightMatrix - 1){
			PrintLog("δ�ҵ����ֵ:��������\n");
			return -1;
		}
		for(int j = 0; j < WidthMatrix; j++){
			if(abs(A[a][j]) > abs(A[a][max_index])){
				max_index= j;
			}
		}
		PrintLog("�ҵ��������ֵ\n");
		break;
	default:
		PrintLog("δ�ҵ����ֵ:��־����\n");
		return -1;
		break;
	}
	return max_index;
}

void Test(){
	double initMatrix[HeightMatrix][WidthMatrix] = {
		{0, 1, 2, 3},
		{1, 2, 5, 3},
		{6, 4, 3, 4},
		{2, 5, 3, 2}
	};
	InitializeMatrix(initMatrix);
	///////////////////////��/�н�������
	//SwapMatrix(0, 4, 'c');
	//SwapMatrix(1, 4, 'r');
	SwapMatrix(1, 1, 's');
	//////////////////////���ֵ���Ҳ���
	/*int a = 3;
	int b = MaxArray(a, 'r');
	cout<<"("<<a<<","<<b<<")"<<A[a][b];*/
	//PrintMatrix(A);
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
		cout<<"��Ԫ��|A["<<a<<"]["<<j<<"]| = "<<abs(A[a][j])<<endl;
		//������Ԫ���кͶ�Ӧ��
		SwapMatrix(a, j, 'r');
		cout<<"������Ԫ����"<<a<<"��"<<j<<endl;
		
		//��Ԫ
		for(int i = 0; i < HeightMatrix; i++){
			if(i == j){//ͬһ��û����
				continue;
			}
			double coffient = -A[i][j] / A[j][j];
			cout<<A[i][j]<<"/"<<A[j][j]<<"="<<coffient<<endl;
			for(int k = 0; k < WidthMatrix; k++){
				A[i][k] = A[i][k] + coffient * A[i][j];
				//issues
			}PrintMatrix(A);
		}break;
	}
	//Test();
	getchar();
}
