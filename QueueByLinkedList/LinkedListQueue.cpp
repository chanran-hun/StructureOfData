#include <iostream>
using namespace std;

class LinkedListNode {
public:
	int data;				//��忡 �� ��
	LinkedListNode* next;	//���� ��带 ����Ŵ
	LinkedListNode(int value) {	//����� ������, ���� ������ data�� �ʱ�ȭ �ϰ� next�� NULL�� �ʱ�ȭ
		data = value;
		next = nullptr;
	}
};

class Queue {
	LinkedListNode* front;	
	LinkedListNode* back;
public:
	Queue() {
		front = nullptr;
		back = nullptr;	//Queue�� ������, front�� back�� ��� NULL�� �ʱ�ȭ ��
	}

	void enQueue(int value) {	//���ο� �� ����
		LinkedListNode* node = new LinkedListNode(value);	//��� ����
		if (this->back == nullptr) {
			this->front = node;
			this->back = node;
		}
		else {
			this->back->next = node;
			this->back = node;
		}
	}

	int deQueue() {
		if (this->front == nullptr) {
			cout << "����ֽ��ϴ� deQueue ����!" << endl;
			return -1;
		}
		int value = this->front->data;
		this->front = this->front->next;
		if (this->front == nullptr) {
			cout << "���� �����Ͱ� �����ϴ�" << endl;
			this->back = nullptr;
		}
		return value;
	}

	void show() {
		LinkedListNode* node = this->front;
		while (node != nullptr) {
			cout << node->data << "->";
			node = node->next;
		}
		cout << "NULL" << endl;
	}
};

int main() {
	Queue myQueue;

	myQueue.enQueue(1);
	myQueue.enQueue(2);
	myQueue.enQueue(3);

	myQueue.show();

	cout << "deQueue ��:" << myQueue.deQueue() << endl;

	myQueue.show();
	
	return 0;
}
//ť�� ���Լ����̴� ���� ���� ��û�� ���� ó���ؾ��ϴ� �������� ������ �����ϴ�. 
//�ݸ鿡 ������ �ֱ� �׸��� ���� ó���ؾ� �� ���� ������ �����ϴ�. �ֱ� �׸��� ó���ϰ� �� ���¿��� ���� �ϰ� �Ǹ� ����
//���·� ���ƿ��� ���� ����� ���� �� �ִ�.