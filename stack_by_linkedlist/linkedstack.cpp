#include <iostream>
using namespace std;

class LinkedListNode {	//��� Ŭ����, ������ ���� ������ ���� ��带 ����Ų��.
public:
	int data;
	LinkedListNode* next;

	LinkedListNode(int d) {	//�����Ͱ��� �޾Ƽ� �ʱ�ȭ ��Ű�� �����ʹ� NULL�� ����Ű�� �ʱ�ȭ
		data = d;
		next = nullptr;
	}
};

class Stack {	//���� Ŭ����
public:
	LinkedListNode* head;	//Linked List�� head

	Stack() {
		head = nullptr;		//head�� NULL�� �ʱ�ȭ
	}

	~Stack() {
		while (head != nullptr) {
			LinkedListNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push(int value) {	//���ο� ��ü �߰�
		LinkedListNode* node = new LinkedListNode(value);

		node->next = head;	//head �տ� ���ο� ��ü ����
		head = node;	//head ����

		cout << value << "��/�� ���� �߰��մϴ�" << endl;
	}

	int pop() {		//�ֻ�� ��� ��������, �� ��ȯ
		if (this->head == nullptr) {
			cout << "������ ��� �ֽ��ϴ�." << endl;
			return -1; // ���� �ڵ� ��ȯ
		}

		int value = 0;

		if (this->head != nullptr) {
			LinkedListNode* temp = head;
			value = temp->data;		//�ֻ�� �� �ٸ����� �Űܴ��
			head = head->next;	//head ����
			delete temp;
		}

		return value;	//������ �ֻ�� �� ��ȯ
	}

	void show() {	//Stack�� �� ���� ����ȭ
		cout << "���� Stack ���� ����ȭ: ";

		LinkedListNode* temp = head;

		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next;
		}

		cout << "NULL" << endl;
	}
};

int main() {
	Stack myStack;

	myStack.push(1);
	myStack.push(2);	//1���� 3 �߰�
	myStack.push(3);

	myStack.show();		//���� Stack���� ����ȭ

	cout << myStack.pop() << "���� �� ��ȯ" << endl;		//���� �ֱٿ� �߰��� �� ���� �� ��ȯ

	myStack.show();		//���� Stack���� ����ȭ

	return 0;
}     