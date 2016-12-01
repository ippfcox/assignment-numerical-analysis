#include<iostream>
#include<math.h>

using namespace std;
/**********************
完成了矩阵的相关操作，初始化、显示、行/列交换，查找行/列最大值
2016.11.30 20:03
ippfcox
***********************/

const int HeightMatrix = 4;//行数
const int WidthMatrix = 5;//列数
bool log_flag = true;
double A[HeightMatrix][WidthMatrix] = {0};

void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]);
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]);
void PrintLog(char log[]);
void SwapMatrix(int a, int b, char direction);
int ColumnPrimaryElement(int j);
int MaxArray(int a, char direction);
void Test();

//输出信息
void PrintLog(char log[]){
	if(log_flag){
		cout<<log;
		//PrintMatrix(A);
	}
}
//显示当前矩阵,进行简化修改
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]){
	for(int i = 0; i < HeightMatrix; i++){
		for(int j = 0; j < WidthMatrix; j++){
			cout<<matrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
//用很笨的方法初始化矩阵
void InitializeMatrix(double initMatrix[HeightMatrix][WidthMatrix]){
	for(int i = 0; i < HeightMatrix; i++){
		for(int j = 0; j < WidthMatrix; j++){
			A[i][j] = initMatrix[i][j];
		}
	}
	PrintLog("矩阵被初始化为\n");
	PrintMatrix(A);
}
//交换矩阵的行或者列，开头为0！！！
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
//没有必要查找行最大值，列主元素也不是在整列中查找[j, MaxHeight]
int ColumnPrimaryElement(int j){
	int max_index = j;
	for(int i = j + 1; i < HeightMatrix; i++){
		if(abs(A[i][j]) > abs(A[max_index][j])){
			max_index = i;
		}
	}
	return max_index;
}
//查找某行/列的绝对值最大值，返回索引
int MaxArray(int a, char direction){
	int max_index = 0;
	switch(direction){
	case 'c':
		if(a < 0 || a > WidthMatrix - 1){
			PrintLog("未找到最大值:索引错误\n");
			return -1;
		}
		for(int i = 1; i < HeightMatrix; i++){
			if(abs(A[i][a]) > abs(A[max_index][a])){
				max_index= i;
			}
		}
		PrintLog("找到了列最大值\n");
		break;
	case 'r':
		if(a < 0 || a > HeightMatrix - 1){
			PrintLog("未找到最大值:索引错误\n");
			return -1;
		}
		for(int j = 0; j < WidthMatrix; j++){
			if(abs(A[a][j]) > abs(A[a][max_index])){
				max_index= j;
			}
		}
		PrintLog("找到了行最大值\n");
		break;
	default:
		PrintLog("未找到最大值:标志错误\n");
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
	///////////////////////行/列交换测试
	//SwapMatrix(0, 4, 'c');
	//SwapMatrix(1, 4, 'r');
	SwapMatrix(1, 1, 's');
	//////////////////////最大值查找测试
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
		//列选主元素
		int a = ColumnPrimaryElement(j);
		cout<<"主元素|A["<<a<<"]["<<j<<"]| = "<<abs(A[a][j])<<endl;
		//交换主元素行和对应行
		SwapMatrix(a, j, 'r');
		cout<<"交换主元素行"<<a<<"和"<<j<<endl;
		
		//消元
		for(int i = 0; i < HeightMatrix; i++){
			if(i == j){//同一行没得消
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
