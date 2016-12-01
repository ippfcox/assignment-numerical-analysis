#include<iostream>
#include<math.h>

using namespace std;
/**********************
完成了矩阵的相关操作，初始化、显示、行/列交换，查找列主元素
完成了方程求解流程并输出了正确结果

1.设置矩阵的行和列的长度
2.设置初始化矩阵
3.F5

2016.12.01 14:57
ippfcox
***********************/

const int HeightMatrix = 4;//行数
const int WidthMatrix = 5;//列数
bool log_flag = false;
double A[HeightMatrix][WidthMatrix] = {0};

void PrintLog(char log[]);
void PrintMatrix();
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]);
void SwapMatrix(int a, int b, char direction);
int ColumnPrimaryElement(int j);

//输出信息
void PrintLog(char log[]){
	if(log_flag){
		cout<<log;
	}
}
//显示当前矩阵
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
//初始化矩阵
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]){
	for(int i = 0; i < HeightMatrix; i++){
		for(int j = 0; j < WidthMatrix; j++){
			A[i][j] = initMatrix[i][j];
		}
	}
	PrintLog("矩阵被初始化为\n");
	PrintMatrix();
}
//交换矩阵的行或者列，以0开始
void SwapMatrix(int a, int b, char direction){
	switch(direction){
	case 'c':
		//检查交换越界
		if(a < 0 || a > WidthMatrix - 1 || b < 0 || b > WidthMatrix - 1 || a == b){
			PrintLog("未交换:索引错误\n");
			return;
		}
		for(int i = 0; i < HeightMatrix; i++){
			double tmp = A[i][a];
			A[i][a] = A[i][b];
			A[i][b] = tmp;
		}
		PrintLog("交换了列\n");
		break;
	case 'r':
		if(a < 0 || a > HeightMatrix - 1 || b < 0 || b > HeightMatrix - 1 || a == b){
			PrintLog("未交换:索引错误\n");
			return;
		}
		for(int j = 0; j < WidthMatrix; j++){
			double tmp = A[a][j];
			A[a][j] = A[b][j];
			A[b][j] = tmp;
		}
		PrintLog("交换了行\n");
		break;
	default:
		PrintLog("未交换:标志错误\n");
		break;
	}
}
//查找列主元素，范围[j, MaxHeight]
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
		//列选主元素
		int a = ColumnPrimaryElement(j);
		cout<<"第"<<j<<"列主元素:|A["<<a<<"]["<<j<<"]| = "<<abs(A[a][j])<<endl;
		//交换主元素行和对应行
		SwapMatrix(a, j, 'r');
		cout<<"交换主元素行"<<a<<"和"<<j<<endl;
		
		//消元
		for(int i = 0; i < HeightMatrix; i++){
			//同一行没得消
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
	//去因数
	for(int i = 0; i < HeightMatrix; i++){
		A[i][WidthMatrix - 1] /= A[i][i];
		A[i][i] = 1;
	}
	cout<<"最终矩阵:"<<endl;
	PrintMatrix();
	cout<<"计算结果:"<<endl;
	for(int i = 0; i < HeightMatrix; i++){
		cout<<"x"<<i+1<<" = "<<A[i][WidthMatrix - 1]<<endl;
	}
	getchar();
}
