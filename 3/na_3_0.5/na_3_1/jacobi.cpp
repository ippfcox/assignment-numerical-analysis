#include<iostream>

using namespace std;
/****************************************
这段程序没有完成，其中有点错误
我觉得不应该用这种方法来解决这个问题，而是应该用更直接的方法
毕竟公式推导的目的不是为了在计算机上重复(ﾉ*･ω･)ﾉ的过程
而是简化计算机上的实现

关于这个小错误应该是在迭代部分，但是暂时就这样不进行修改了。

突然想玩点有意思的，再说吧。

2016.12.06 15:54
ippfcox@717

Update
关于上面提到的错误可能是误会，因为我发现那个矩阵我写错了
计算结果也跟另一个程序差不多，这个就比较尴尬了

2016.12.06 22:24
****************************************/
const int HeightMatrix = 3;
const int WidthMatrix = 3;

double A[HeightMatrix][WidthMatrix] = { 0 };//系数矩阵
double b[HeightMatrix][1] = { 0 };//值
double D[HeightMatrix][WidthMatrix] = { 0 };//对角阵
double L_U[HeightMatrix][WidthMatrix] = { 0 };//上下三角
double Bj[HeightMatrix][WidthMatrix] = { 0 };//矩阵 $$B_j = -D^{-1}(L + U)$$
double D_b[HeightMatrix][1] = { 0 };//矩阵 $$D_b = D^{-1}b$$
double x[HeightMatrix][1] = { 0 };//解向量

//函数声明
void InitializeA(double initMatrix[HeightMatrix][WidthMatrix + 1]);
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]);
void PrintEquations();
void SplitA();
void CreateBj();
void Iterate();

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
//将矩阵A拆分成对角阵和上下三角矩阵
void SplitA() {
	if (HeightMatrix != WidthMatrix) {
		cout << "发生了错误";
		return;
	}
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix; j++) {
			if (i == j) {
				D[i][j] = A[i][j];
			} else {
				L_U[i][j] = A[i][j];
			}
		}
	}
}
//生成Bj矩阵
void CreateBj() {
	for (int i =0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix; j++) {
			Bj[i][j] = L_U[i][j] / -D[i][i];
		}
	}
}
//生成D逆b矩阵，啊啊啊设置打印太占地方了，不弄了
void CreateD_b() {
	for (int i = 0; i < HeightMatrix; i++) {
		D_b[i][0] = b[i][0] / D[i][i];
	}
}
//迭代过程
void Iterate(){
	double xi0[HeightMatrix][1] = { 0 };
	for (int i = 0; i < HeightMatrix; i++) {
		xi0[i][0] = x[i][0];
	}
	for (int i = 0; i < HeightMatrix; i++) {
		double tmp[HeightMatrix][1] = { 0 };//Bj*xi的临时矩阵
		for (int j = 0; j < WidthMatrix; j++) {
			tmp[i][0] += Bj[i][j] * xi0[j][0];//cout<<endl<<tmp[i][0]<<endl;
		}
		x[i][0] = tmp[i][0] + D_b[i][0];
		//cout << endl << tmp[i][0] << "|" << D_b[i][0] << endl;
	}
}
void PrintSolution() {
	cout << "---------------------------" << endl;
	for (int i = 0; i < HeightMatrix; i++) {
		cout << "x" << i + 1 << " = " << x[i][0] << endl;
	}
	cout << "---------------------------" << endl;
}
//打印列向量
void PrintColumnArray(double columnArray[HeightMatrix][1]) {
	cout << "---------------------------" << endl;
	for (int i = 0; i < HeightMatrix; i++) {
		cout << columnArray[i][0] << endl;
	}
	cout << "---------------------------" << endl;
}
//打印矩阵
void PrintMatrix(double matrix[HeightMatrix][WidthMatrix]) {
	cout << "---------------------------" << endl;
	for (int i = 0; i < HeightMatrix; i++) {
		for (int j = 0; j < WidthMatrix; j++) {
			cout << matrix[i][j] << "  \t";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
}
//打印方程组，用以观察b的内容
void PrintEquations() {
	cout << "---------------------------" << endl;
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
	cout << "---------------------------" << endl;
}
void main() {
	/*double tmpA_b[HeightMatrix][WidthMatrix + 1] = {
		{4, -1, 0, 2},
		{-1, 4, -1, 6},
		{0, -1, 4, 2}
	};*/
	double tmpA_b[HeightMatrix][WidthMatrix + 1] = {
		{1.4, 23.9, 12.4, 15.9},
		{3.1, -2.8, 8.3, 8.3},
		{13.8, 2.6, -3.4, 29.1}
	};
	//double tmpA_b[HeightMatrix][WidthMatrix + 1] = {
	//	{5.2, -9.5, 1.4, -24.5, 2.8},
	//	{2.4, 1.7, 16.1, 5.1, -7.3},
	//	{5.3, 21.3, -4.8, 4.2, -3.1},
	//	{14.7, 5.7, -1.4, 3.5, 1.5}
	//};

	InitializeA(tmpA_b);
	PrintEquations();
	PrintMatrix(A);
	PrintColumnArray(b);
	SplitA();
	PrintMatrix(D);
	PrintMatrix(L_U);
	CreateBj();
	PrintMatrix(Bj);
	CreateD_b();
	PrintColumnArray(D_b);
	for (int count = 0; count < 20; count ++) {
		Iterate();
		PrintSolution();
	}

	getchar();
}