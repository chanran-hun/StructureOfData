#include <iostream>
using namespace std;

class Queue {
	int front;
	int back;
	int* array;
	int array_size;
	int reset;
	int count; // ���� ť�� �ִ� ����� ������ �����ϴ� ����
public:
	Queue(int n) {	//�迭 ũ�⸦ �Է¹ް� �ּ���, ���Ĺ�, ��¿� ������ reset�� 0���� �ʱ�ȭ�ϰ� �迭ũ�⸸ŭ�� 
					//�迭 �����Ҵ�
		array_size = n;
		front = 0;
		back = 0;
		array = new int[array_size];
		reset = 0;
		count = 0; // ť�� �ʱ� ���´� ��� ����
	}

	void enqueue(int n) {	//���ο� �� �߰�
		if (count == array_size) { // �迭�� ���� �� ����
			cout << "���� ����: ť�� ���� á���ϴ�." << endl;
			return;
		}

		array[back] = n;
		back = (back + 1) % array_size; // back�� ���� �����Ͽ� ��ȯ ó��
		count++; // ť�� ��Ҹ� �ϳ� �߰�
		cout << n << " �߰� ����!" << endl;
	}

	bool isEmpty() {
		// count ������ ����Ͽ� ����ִ��� Ȯ��
		return count == 0;
	}

	int dequeue() {
		if (isEmpty()) { // ť�� ��� �ִ��� Ȯ��
			cout << "���� ����: ť�� ��� �ֽ��ϴ�." << endl;
			return -1; // ���� ���� ��ȯ�ϴ� ��� ���и� �˷���
		}

		int value = array[front];
		front = (front + 1) % array_size; // front�� ��ȯ ó��
		count--; // ť���� ��Ҹ� �ϳ� ����
		return value;
	}

	void show() {
		cout << "���� Queue ���� ����ȭ | ";
		if (count == 0) {
			cout << "ť�� ��� �ֽ��ϴ�." << endl;
		} else {
			for (int i = 0; i < count; i++) {
				int index = (front + i) % array_size; // front���� count���� ��� ���
				cout << array[index] << " | ";
			}
			cout << endl;
		}
	}
};

int main() {
	Queue myQueue = Queue(5);

	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " ���� �� ��ȯ" << endl;
	} else {
		cout << "ť�� ��� �ֽ��ϴ�." << endl;
	}

	myQueue.enqueue(1);	//1���� 5���� ť ������ ���� �߰���
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);

	myQueue.show();		//���� Stack�� ���¸� ����ȭ�ϱ�

	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " ���� �� ��ȯ" << endl;
	} else {
		cout << "ť�� ��� �ֽ��ϴ�." << endl;
	}
	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " ���� �� ��ȯ" << endl;//���� ���� �߰��� ������ �տ������� 3�� 
	} else {												//���� �� ���
		cout << "ť�� ��� �ֽ��ϴ�." << endl;
	}		
	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " ���� �� ��ȯ" << endl;
	} else {
		cout << "ť�� ��� �ֽ��ϴ�." << endl;
	}				

	myQueue.show();		//���� Stack�� ���¸� ����ȭ�ϱ�

	myQueue.enqueue(6);	//6���� 8���� ť ������ ���� �߰���
	myQueue.enqueue(7);
	myQueue.enqueue(8);

	myQueue.show();		//���� Stack�� ���¸� ����ȭ�ϱ�

	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " ���� �� ��ȯ" << endl;	//���� ���� �߰��� ���� 1�� ���� �� ���
	} else {
		cout << "ť�� ��� �ֽ��ϴ�." << endl;
	}						

	myQueue.enqueue(9);	//9�� ť ������ �߰���

	myQueue.show();		//���� Stack�� ���¸� ����ȭ��

	myQueue.enqueue(10);	//10�� ť ������ �߰���

	return 0;
}