#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
queue<char> orderstr; //���ö���
char levelstr[10000];
char pre[10000];
char in[10000];
char result[10000];
void preOrder(int i, int length) { //�ݹ��㷨��ǰ�����
	orderstr.push(pre[i]);  //�����ڵ�
	if (2 * i <= length) {
		preOrder(2 * i, length);
	}
	if (2 * i + 1 <= length) {
		preOrder(2 * i + 1, length);
	}
}
void inOrder(int i, int length) { //�ݹ��㷨���������
	if (2 * i <= length) {
		inOrder(2 * i, length);
	}
	orderstr.push(pre[i]);
	if (2 * i + 1 <= length) {
		inOrder(2 * i + 1, length);
	}
}
void postOrder(int i, int length) {//�ݹ��㷨��������
	if (2 * i <= length) {
		postOrder(2 * i, length);
	}
	if (2 * i + 1 <= length) {
		postOrder(2 * i + 1, length);
	}
	orderstr.push(pre[i]);
}
void levelOrder(int n, int start, int end, int start2, int end2) {//����ǰ�б����õ���α���
	if (start > end)
		return;
	result[n] = pre[start];
	for (int i = start2; i <= end2; ++i) {
		if (in[i] == pre[start]) {
			levelOrder(n * 2, start + 1, start + i - start2, start2, i - 1);
			levelOrder(n * 2 + 1, start + 1 + i - start2, end, i + 1, end2);
		}
	}
}
int main()
{
	cout << "Input1" << endl;
	cin >> levelstr; //�����ֱ�Ӵ�Ϊ����
	int length = strlen(levelstr); //��ֱ�ӵõ������Ŀ
	for (int i = 1; i <= length; ++i) {
		pre[i] = levelstr[i - 1];
	}
	cout << "Output1" << endl;

	preOrder(1, length); //ǰ�����
	while (orderstr.size()) { //���ǰ�����������Ķ���
		cout << orderstr.front();
		orderstr.pop(); //��ջ
		if (orderstr.size() != 0) {
			cout << ",";
		}
	}
	cout << endl;
	inOrder(1, length); //�������
	while (orderstr.size()) { //���ǰ�����������Ķ���
		cout << orderstr.front();
		orderstr.pop(); //��ջ
		if (orderstr.size() != 0) {
			cout << ",";
		}
	}
	cout << endl;
	postOrder(1, length); //�������
	while (orderstr.size()) { //���ǰ�����������Ķ���
		cout << orderstr.front();
		orderstr.pop(); //��ջ
		if (orderstr.size() != 0) {
			cout << ",";
		}
	}
	cout << endl;
	cout << length << endl; //�����Ŀ
	int t = 1;
	int high;
	for (high = 1;; ++high) { //��߶�
		t *= 2;
		if (t > length)
			break;
	}
	cout << high << endl;

	cout << "Input2" << endl;
	cin >> levelstr;
	length = strlen(levelstr); //�õ������Ŀ
	for (int i = 1; i <= length; ++i) {
		pre[i] = levelstr[i - 1];
	}
	cin >> levelstr;
	for (int i = 1; i <= length; ++i) {
		in[i] = levelstr[i - 1];
	}
	levelOrder(1, 1, length, 1, length);
	for (int i = 1; i <= length; ++i) {
		pre[i] = result[i];
	}
	postOrder(1, length); //�������
	cout << "Output2" << endl;
	while (orderstr.size()) {
		cout << orderstr.front();
		orderstr.pop();
		if (orderstr.size() != 0) {
			cout << ",";
		}
	}
	cout << endl;
	for (int i = 1; i <= length; ++i)
	{
		cout << result[i];
		if (i < length )
			cout << ",";
	}
	cout << endl;
	cout << "End";
	return 0;
}