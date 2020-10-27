#include <iostream>
using namespace std;
void sort1(int a[], int n) { //ð������
	for (int i = 1; i < n; i++) {//����n-1��
		for (int j = 0; j < n-1; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);//����Ƚ�  (n-1��!�Ρ�
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1)
			cout << ",";
	}
	cout << endl;
}
void sort2(int a[], int n) { //��������ע��Ӵ���С�ķ���ȥ�Ƚ�
	int temp[20];
	for (int i = 0; i < n; i++) {
		temp[i] = a[i];
		for (int j = i; j > 0; j--) {
			if (temp[j] >= temp[j - 1])
				break;
			else
				swap(temp[j - 1], temp[j]);
		}
	}
	for (int m = 0; m < n; m++)
		a[m] = temp[m];
	for (int j = 0; j < n; j++) {
		cout << a[j];
		if (j != n - 1)
			cout << ",";
	}
	cout << endl;
}
void sort3(int a[], int n) { //��������
	int flag = 1;
	int count[10];
	int temp[20];
	for (int i = 0; i < 10; ++i) //��Ͱ���� 
		count[i] = 0;
	for (int i = 0; i < n; i++) { //ÿ�������� 
		int p = a[i] % 10;
		count[p] ++;
	}
	for (int j = 1; j < 10; j++) { //������λ���� 
		count[j] += count[j - 1];
	}
	for (int k = n - 1; k >= 0; k--) { //��֤���������� 
		int p = a[k] % 10;
		if (a[k] / 10 != 0) {
			cout << "0" << endl;
			flag = 0;
			break;
		}
		temp[count[p] - 1] = a[k];
		count[p] --;
	}
	for (int m = 0; m < n; m++) {
		a[m] = temp[m];
	}
	if (flag == 1) {
		for (int i = 0; i < n; ++i) {
			cout << a[i];
			if (i != n - 1)
				cout << ",";
		}
		cout << endl;
	}
}
int main() {
	int array[20];
	int length, n, decision;
	cout << "Input" << endl;
	for (int i = 0; i < 20; ++i) {
		cin >> n;
		if (n == 0)
			break;
		array[i] = n;
		length = i + 1;
	}
	cout << "1-ð������2-��������3-��������";
	cin >> decision;
	cout << "Output" << endl;
	switch (decision) {
	case 1:
		cout << "ð������" << endl;
		sort1(array, length);
		break;
	case 2:
		cout << "��������" << endl;
		sort2(array, length);
		break;
	case 3:
		cout << "��������" << endl;
		sort3(array, length);
		break;
	}
	cout << "End" << endl;
	cout << "�밴���������������";
}