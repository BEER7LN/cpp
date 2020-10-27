#include <iostream>
using namespace std;
void swap(int& a, int& b) { //swap��������������a,b��λ�õ�ֵ
	int temp = a;
	a = b;
	b = temp;
}
void permutations(int arry[], int k, int n) {
	if (k == n) { //�Ѿ����������һ��Ԫ��
		for (int i = 0; i <= n; i++) { //����������з�ʽ
			cout << arry[i];
			if (i < n) cout << ",";
		}
		cout << endl;
	}
	else {
		for (int i = k; i <= n; i++) {
			swap(arry[k], arry[i]); //i��k��ʼȷ��Ԫ��
			permutations(arry, k + 1, n); //��k+1��֮���Ԫ������
			swap(arry[k], arry[i]); //��k��i��Ԫ�ظ�ԭ��ѭ������k��i+1��Ԫ��
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