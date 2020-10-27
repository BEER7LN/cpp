#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
queue<char> orderstr; //运用队列
char levelstr[10000];
char pre[10000];
char in[10000];
char result[10000];
void preOrder(int i, int length) { //递归算法求前序遍历
	orderstr.push(pre[i]);  //读根节点
	if (2 * i <= length) {
		preOrder(2 * i, length);
	}
	if (2 * i + 1 <= length) {
		preOrder(2 * i + 1, length);
	}
}
void inOrder(int i, int length) { //递归算法求中序遍历
	if (2 * i <= length) {
		inOrder(2 * i, length);
	}
	orderstr.push(pre[i]);
	if (2 * i + 1 <= length) {
		inOrder(2 * i + 1, length);
	}
}
void postOrder(int i, int length) {//递归算法求后序遍历
	if (2 * i <= length) {
		postOrder(2 * i, length);
	}
	if (2 * i + 1 <= length) {
		postOrder(2 * i + 1, length);
	}
	orderstr.push(pre[i]);
}
void levelOrder(int n, int start, int end, int start2, int end2) {//根据前中遍历得到层次遍历
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
	cin >> levelstr; //输入后直接存为数组
	int length = strlen(levelstr); //可直接得到结点数目
	for (int i = 1; i <= length; ++i) {
		pre[i] = levelstr[i - 1];
	}
	cout << "Output1" << endl;

	preOrder(1, length); //前序遍历
	while (orderstr.size()) { //输出前序遍历调整后的队列
		cout << orderstr.front();
		orderstr.pop(); //出栈
		if (orderstr.size() != 0) {
			cout << ",";
		}
	}
	cout << endl;
	inOrder(1, length); //中序遍历
	while (orderstr.size()) { //输出前序遍历调整后的队列
		cout << orderstr.front();
		orderstr.pop(); //出栈
		if (orderstr.size() != 0) {
			cout << ",";
		}
	}
	cout << endl;
	postOrder(1, length); //后序遍历
	while (orderstr.size()) { //输出前序遍历调整后的队列
		cout << orderstr.front();
		orderstr.pop(); //出栈
		if (orderstr.size() != 0) {
			cout << ",";
		}
	}
	cout << endl;
	cout << length << endl; //结点数目
	int t = 1;
	int high;
	for (high = 1;; ++high) { //求高度
		t *= 2;
		if (t > length)
			break;
	}
	cout << high << endl;

	cout << "Input2" << endl;
	cin >> levelstr;
	length = strlen(levelstr); //得到结点数目
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
	postOrder(1, length); //后序遍历
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