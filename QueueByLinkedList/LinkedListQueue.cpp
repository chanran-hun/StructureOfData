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
	LinkedListNode* front;	//������ ���
	LinkedListNode* back;	//���Ĺ� ���
public:
	Queue() {
		front = nullptr;
		back = nullptr;	//Queue�� ������, front�� back�� ��� NULL�� �ʱ�ȭ ��
	}

	void enQueue(int value) {	//���ο� �� ����
		LinkedListNode* node = new LinkedListNode(value);	//��� ����
		if (this->back == nullptr) {	//���� ��尡 �ϳ���� �� ���� front���� back�� �ȴ�
			this->front = node;
			this->back = node;
		}	
		else {
			this->back->next = node;	//�ڿ� �ϳ��� �߰��ߴٸ� �� �߰��� ��尡 back�� �Ǿ�� �Ѵ�.
			this->back = node;
		}

		cout << value << "���� ����!" << endl;
	}

	int deQueue() {
		if (this->front == nullptr) {
			cout << "����ֽ��ϴ� deQueue ����!" << endl;		//queue�� ����ִٸ� dequeue�� �Ұ����ϴ�
			return -1;
		}
		int value = this->front->data;		//front ����� �����Ͱ��� �����صд�.
		LinkedListNode* temp = this->front;	//������ front�� �����صд�
		this->front = this->front->next;	//front ���� ��尡 front�� �ǰ� �Ѵ�.
		delete temp;	//������ front�� �����ϴ� �޸� �ݳ�
		if (this->front == nullptr) {
			cout << "���� �����Ͱ� �����ϴ�" << endl;		//���� dequeue�� ���� queue�� ������ ���̾��ٸ� 
			this->back = nullptr;						//back�� NULL�� �Ǿ���Ѵ�.
		}
		return value;
	}

	void show() {	//���� queue�� ���¸� ����ȭ �Ѵ�.
		cout << "Queue�� ���� ���� ����ȭ :";
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

	myQueue.enQueue(1);	//Queue�� 1���� 3���� �����Ѵ�
	myQueue.enQueue(2);
	myQueue.enQueue(3);
		
	myQueue.show();	//Queue����ȭ

	cout << myQueue.deQueue() << "���� �� ��ȯ" << endl;	//������ ���� ���� �� ��ȯ�Ѵ�

	myQueue.show();	//Queue����ȭ
	
	return 0;
}
//ť�� ���Լ����̴� ���� ���� ��û�� ���� ó���ؾ��ϴ� �������� ������ �����ϴ�. 
//�ݸ鿡 ������ �ֱ� �׸��� ���� ó���ؾ� �� ���� ������ �����ϴ�. �ֱ� �׸��� ó���ϰ� �� ���¿��� ���� �ϰ� �Ǹ� ����
//���·� ���ƿ��� ���� ����� ���� �� �ִ�.