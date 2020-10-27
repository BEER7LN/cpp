#include <iostream>
using namespace std;
void swap(int& a, int& b) { //swap函数交换数组中a,b两位置的值
	int temp = a;
	a = b;
	b = temp;
}
void permutations(int arry[], int k, int n) {
	if (k == n) { //已经排完了最后一个元素
		for (int i = 0; i <= n; i++) { //输出该种排列方式
			cout << arry[i];
			if (i < n) cout << ",";
		}
		cout << endl;
	}
	else {
		for (int i = k; i <= n; i++) {
			swap(arry[k], arry[i]); //i从k开始确定元素
			permutations(arry, k + 1, n); //对k+1及之后的元素排列
			swap(arry[k], arry[i]); //将k、i处元素复原后循环交换k、i+1处元素
		}
	}
}
int main() {
	int arry[21];
	int length=0;
	cout << "Input" << endl;
	for (int i = 0; i < 21; i++) {
		cin >> arry[i];
		if (arry[i] == 0) {
			length = i;
			break;
		}
	}
	cout << endl;
	cout << "Output" << endl;
	permutations(arry, 0, length-1);
	cout << "end" << endl;
	return 0;
}