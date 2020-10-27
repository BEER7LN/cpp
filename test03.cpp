#include <iostream>
using namespace std;

struct ListNode {
	int data;
	struct ListNode* next;
};
void createList(ListNode* head) { //����������
	ListNode* p = head; //Ϊhead������ָ��
	int n;
	cin >> n;
	p->data = n; //�����׽��ֵΪ��
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
void Listsort(ListNode* head) { //��������
	ListNode* p = NULL;
	ListNode* q = NULL;
	int temp;
	for (p = head; p != NULL; p = p->next) { //���׽�㿪ʼѡ����Сֵ
		for (q = p->next; q != NULL; q = q->next) { //ÿһ�α���ȷ��һ��λ�õ�ֵ
			if (p->data > q->data) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}
void outputList(ListNode* head) { //��ʽ���������
	ListNode* p = head;
	while (p != NULL) {
		cout << p->data;
		if (p->next != NULL)
			cout << ",";
		p = p->next;
	}
	cout << endl;
}
void insertNode(ListNode* head,int num) { //������
	for (ListNode* p = head; p->data < num; p = p->next) {
		if (p->next != NULL && p->next->data >= num ) { //�������м����
			ListNode* newnode = new ListNode;
			newnode->data = num;
			newnode->next = p->next;
			p->next = newnode;
		}
		else if (p->next == NULL) { //������ĩ����
			ListNode* newnode = new ListNode;
			newnode->data = num;
			newnode->next = NULL;
			p->next = newnode;
		}
	}
}
int indexOf(ListNode* head,int theElement) { //����������ĳ����Index
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
ListNode* merge(ListNode* head1, ListNode* head2) { //�ݹ�ϲ�������������
	//ÿ����һ�Σ���õ�һ��ֵ����Ҫnewһ��
	ListNode* p = new ListNode;
	//ע�������ж��ڱȽϺ͵ݹ�֮ǰ�������������ж��ǽ��������صĹؼ���returnʱ��head1��head2��ָ�����������沿�ֵ�
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
	ListNode* head1 = NULL;//����ָ�벢��ʼ��
	head1 = new ListNode;//�����ڴ�
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
	cout << "�밴���������...";

	return 0;
}