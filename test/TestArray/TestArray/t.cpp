#include<iostream>
using namespace std;

void PrintArray(int arr[3]);
void main() {
	int a[3] = {1, 2, 3};
	int b[3] = {9, 8, 7};
	cout << "Array a:";
	PrintArray(a);
	cout << "Array b:";
	PrintArray(b);

	*b = *a;

	cout << "Array a:";
	PrintArray(a);
	cout << "Array b:";
	PrintArray(b);
	getchar();
}
void PrintArray(int arr[3]) {
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ".";
	}
	cout << endl;
}