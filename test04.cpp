#include<iostream>
#include <string>
using namespace std;
template <class T>
class stack {
public:
	virtual ~stack() {}
	virtual bool empty() const = 0; //判断堆栈是否为空
	virtual int size() const = 0; //返回元素个数
	virtual T& top() = 0; //返回栈顶元素
	virtual void push(const T& theElement) = 0; //入栈
	virtual void pop() = 0; //出栈
};

template<class T>
class arraystack :public stack<T> {
public:
	arraystack(int initialcapcity);
	~arraystack() { delete[] stack; }
	bool empty() const { return stacktop == -1; } //空栈top=-1
	int size() const { return stacktop + 1; } //元素入栈保存同时top+1
	T& top() {
		return stack[stacktop];
	}
	void pop() {
		if (stacktop != -1)
			stack[stacktop--].~T();
	}
	void push(const T& theElement);

private:
	int stacktop;
	int maxsize; //栈最大容量
	T* stack; //数组
};

template<class T>
arraystack<T>::arraystack(int initialcapacity) {
	if (initialcapacity >= 1) {
		maxsize = initialcapacity;
		stack = new T[maxsize];
		stacktop = -1;
	}
}

template<class T>
void arraystack<T>::push(const T& theElement) {
	if (stacktop != maxsize - 1)
		stack[++stacktop] = theElement;
}
string BehindSew(string str1) { //中缀表达式转换为转换为后缀表达式
	arraystack<char>* stack = new arraystack<char>(100); //只有运算符号需要入栈出栈
	char* str = new char[str1.length()];
	char s[10000];
	strncpy_s(s, str1.c_str(), str1.length());
	int n = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) { //中缀表达式中数字直接存入后缀表达式中
			str[n] = s[i];
			//cout << str[n];
			n++;
			//cout << s[i];
		}
		else { //运算符号
			//char temp = stack->top();
			if (stack->size() == 0 || s[i] == '(') {//栈为空或者是左括号时，直接入栈
				stack->push(s[i]);
				//cout << stack->top();
			}
			else {
				char last1 = stack->top();
				if (s[i] == ')') { //右括号，需要全部出栈，直到左括号
					while (true) {
						char last2 = stack->top(); //可能需要反复进行，故无法直接用last1
						if (last2 == '(') { //左括号出栈但不进入str
							stack->pop();
							break;
						}
						else {
							str[n] = last2; //注意先输入str再出栈
							stack->pop();
							n++;
						}
					}
				}
				else { //其余情况需要先与已经入栈的top运算符的优先级进行比较，直到比top优先级高
					if (last1 == '*' || last1 == '/') { //top为*或/则直接出栈，并将新的运算符入栈
						str[n] = last1;
						n++;
						stack->pop();
						if (s[i] == '*' || s[i] == '/') { //新的运算符为*或/则直接入栈
							stack->push(s[i]);
						}
						else { //新的运算符为+-则把栈中左括号(若存在)后面的运算符全部出栈，后自己入栈
							while (true) {
								if (stack->size() != 0 && stack->top() != '(') {
									char last3 = stack->top();
									str[n] = last3;
									n++;
									stack->pop();
								}
								else
									break;
							}
							stack->push(s[i]);
						}
					}
					else
						stack->push(s[i]);
				}
			}
		}
	}
	if (stack->size() != 0) { //数字全部输出后栈内全部运算符直接输出
		while (true) {
			if (stack->size() == 2 && stack->top() == '+') { //避免打乱先件后减后加的运算的顺序
				char a = stack->top();
				stack->pop();
				if (stack->top() == '-') {
					str[n] = stack->top();
					n++;
					stack->pop();
					str[n] = '-';
					n++;
				}
				else {
					str[n] = a;
					n++;
					str[n] = stack->top();
				}
			}
			else {
				if (stack->size() != 0) {
					char b = stack->top();
					str[n] = b;
					stack->pop();
					n++;
				}
				else
					break;
			}
		}
	}
	return str;
}
int  calculate(string str1) { //用后缀表达式进行运算
	arraystack<int>* stack = new arraystack<int>(100); //只有操作数需要入栈出栈
	char s[1000];

	strncpy_s(s, str1.c_str(), str1.length());
	for (int i = 0; i < str1.length(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) //数字直接入栈
			stack->push(s[i] - 48);
		else { //若为运算符号，取出栈中两个数字进行计算
			int a = stack->top();
			stack->pop();
			int tempresult = 0;
			if (stack->size() != 0) {
				int b = stack->top();
				stack->pop();
				if (s[i] == '+') {
					tempresult = b + a;
				}
				else if (s[i] == '-') {
					tempresult = b - a; //因为a先取出，b后取出，注意被减数和减数的顺序，不要弄反了
				}
				else if (s[i] == '*') {
					tempresult = b * a;
				}
				else if (s[i] == '/') {
					tempresult = b / a; //理同减法
				}
				stack->push(tempresult);
			}
			else {
				stack->push(a);
				break;
			}
		}
	}
	return stack->top();
}
int main() {
	cout << "Input" << endl;
	string input;
	getline(cin, input, '\n'); //getline函数读入一行
	input = BehindSew(input);
	//cout << input;
	cout << "Output" << endl;
	cout << calculate(input) << endl;
	cout << "End";
	return 0;
}