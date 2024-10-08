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

	void push(int value) {	//���ο� ��ü �߰�
		LinkedListNode* node = new LinkedListNode(value);
		node->next = this->head;	//head �տ� ���ο� ��ü ����
		this->head = node;	//head ����
		cout << value << "��/�� ���� �߰��մϴ�" << endl;
	}

	int pop() {		//�ֻ�� ��� ��������, �� ��ȯ
		int value = 0;
		if (this->head != nullptr) {
			value = this->head->data;		//�ֻ�� �� �ٸ����� �Űܴ��
			this->head = this->head->next;	//head ����
		}
		return value;	//������ �ֻ�� �� ��ȯ
	}

	void show() {	//Stack�� �� ���� ����ȭ
		cout << "Stack ����ȭ: ";
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
	myStack.push(2);
	myStack.push(3);
	myStack.show();
	cout << "pop ����! �ֻ�� ��: " << myStack.pop() << endl;
	myStack.show();

	return 0;
}     