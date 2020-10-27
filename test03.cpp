#include <iostream>
using namespace std;

struct ListNode {
	int data;
	struct ListNode* next;
};
void createList(ListNode* head) { //构造新链表
	ListNode* p = head; //为head赋予新指针
	int n;
	cin >> n;
	p->data = n; //避免首结点值为空
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		ListNode* newnode = new ListNode;
		newnode->data = n;
		newnode->next = NULL;
		p->next = newnode;
		p = newnode;
	}
}
void Listsort(ListNode* head) { //链表排序
	ListNode* p = NULL;
	ListNode* q = NULL;
	int temp;
	for (p = head; p != NULL; p = p->next) { //从首结点开始选出最小值
		for (q = p->next; q != NULL; q = q->next) { //每一次遍历确定一个位置的值
			if (p->data > q->data) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}
void outputList(ListNode* head) { //格式化输出链表
	ListNode* p = head;
	while (p != NULL) {
		cout << p->data;
		if (p->next != NULL)
			cout << ",";
		p = p->next;
	}
	cout << endl;
}
void insertNode(ListNode* head,int num) { //插入数
	for (ListNode* p = head; p->data < num; p = p->next) {
		if (p->next != NULL && p->next->data >= num ) { //在链表中间插入
			ListNode* newnode = new ListNode;
			newnode->data = num;
			newnode->next = p->next;
			p->next = newnode;
		}
		else if (p->next == NULL) { //在链表末插入
			ListNode* newnode = new ListNode;
			newnode->data = num;
			newnode->next = NULL;
			p->next = newnode;
		}
	}
}
int indexOf(ListNode* head,int theElement) { //查找链表中某数的Index
	ListNode* p = head;
	int index = 1;
	while (p != NULL && p->data != theElement) {
		p = p->next;
		index++;
	}
	if (p == NULL)
		return 0;
	else
		return index;
}
ListNode* merge(ListNode* head1, ListNode* head2) { //递归合并两组有序链表
	//每调用一次，会得到一个值，需要new一个
	ListNode* p = new ListNode;
	//注意两个判断在比较和递归之前，并且这两个判断是结束并返回的关键，return时的head1、head2是指向最初链表后面部分的
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1->data <= head2->data) {
		p->data = head1->data;
		head1 = head1->next;
	}
	else {
		p->data = head2->data;
		head2 = head2->next;
	}
	p->next = merge(head1, head2);
	return p;
}
int main( ) {
	int n1,n2,n3;
	ListNode* head1 = NULL;//定义指针并初始化
	head1 = new ListNode;//分配内存
	head1->data = NULL;
	head1->next = NULL;
	cout << "Input1" << endl;
	createList(head1);
	Listsort(head1);
	cout << "Output1" << endl;
	outputList(head1);
	cout << "Input2" << endl;
	cin >> n1;
	insertNode(head1, n1);
	cout << "Output2" << endl;
	outputList(head1);
	cout << "Input3" << endl;
	cin >> n2;
	cout << "Output3\n"<<indexOf(head1, n2) <<endl;
	cout << "Input4" << endl;
	cin >> n3;
	cout << "Output4\n" << indexOf(head1, n3) << endl;

	ListNode* head2 = NULL;
	head2 = new ListNode;
	head2->data = NULL;
	head2->next = NULL;
	cout << "Input5" << endl;
	createList(head2);
	Listsort(head2);
	cout << "Output5" << endl;
	outputList(head2);

	ListNode* head3 = NULL;
	head3 = new ListNode;
	head3 = merge(head1, head2);
	outputList(head3);
	cout << "End" << endl;
	cout << "请按任意键继续...";

	return 0;
}