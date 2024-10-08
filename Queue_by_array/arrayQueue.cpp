#include <iostream>
using namespace std;

class Queue {
	int front;
	int back;
	int* array;
	int array_size;
	int reset;
public:
	Queue(int n) {	//�迭 ũ�⸦ �Է¹ް� �ּ���, ���Ĺ�, ��¿� ������ reset�� 0���� �ʱ�ȭ�ϰ� �迭ũ�⸸ŭ�� 
					//�迭 �����Ҵ�
		array_size = n;
		front = 0;
		back = 0;
		array = new int[array_size];
		reset = 0;
	}

	void enqueue(int n) {	//���ο� �� �߰�
		if (back == front && reset != 0) {	//�迭�� ���� ������ ���� ���� ���
			cout << "���̻��� ���� ������ �����ϴ�. ���Խ���!" << endl;
			return;
		}

		if (back == array_size) {	//������ ������ �� �� ��� -> �տ� ������ ���Ҵ��� Ȯ����
			cout << "�� ������ �� á���ϴ�!! �տ� ������ �ִ��� Ȯ���մϴ�." << endl;
			if (front != 0) {	//���ʿ� ������ �ִ� ���
				cout << "ã�ҽ��ϴ�!! ���� ���� ������ �����մϴ�!" << endl;
				back -= array_size;
				reset++;
			}
			else {	//���ʿ� ���� ������ ���� ���
				cout << "�տ��� ���� ������ �����ϴ�. ���� ����!" << endl;
				return;
			}
		} 
		this->array[back] = n;	//���Ĺ��� �ε����� ���� ������
		back++;	//���Ĺ� �ε����� ���� 1 ������Ŵ
		cout << n << "�߰� ����!!" << endl;
	}

	int dequeue() {	//���� ���� �߰��� ���� �����԰� ���ÿ� �� ���� ��ȯ��
		return this->array[this->front++];
	}

	void show() {	//������ Stack������ ����ȭ �ؼ� ������
		cout << "���� Queue ���� ����ȭ | ";
		if (back > front) {	//����� ����� ���
			for (int i = front; i < back; i++) {
				cout << this->array[i] << " | ";
			}
		}
		else {	//���� ���� ���� ������ Ȱ���ϱ� ���ؼ� back�� �ʱ�ȭ �� ��쿡�� front���� ������ �ѹ� ����� �Ŀ�
			for (int i = front; i < array_size; i++) {	//0���� back������ ����ؾ���
				cout << this->array[i] << " | ";
			}
			for (int i = 0; i < back; i++) {
				cout << this->array[i] << " | ";
			}
		}
		cout << endl;
	}
};

int main() {
	Queue myQueue = Queue(5);
	myQueue.enqueue(1);	//1���� 5���� ť ������ ���� �߰���
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);

	myQueue.show();		//���� Stack�� ���¸� ����ȭ�ϱ�

	cout << myQueue.dequeue() << "���� �� ��ȯ" << endl;
	cout << myQueue.dequeue() << "���� �� ��ȯ" << endl;		//���� ���� �߰��� ������ �տ������� 3�� 
	cout << myQueue.dequeue() << "���� �� ��ȯ" << endl;		//���� �� ���

	myQueue.show();		//���� Stack�� ���¸� ����ȭ�ϱ�

	myQueue.enqueue(6);	//6���� 8���� ť ������ ���� �߰���
	myQueue.enqueue(7);
	myQueue.enqueue(8);

	myQueue.show();		//���� Stack�� ���¸� ����ȭ�ϱ�

	cout << myQueue.dequeue() << "���� �� ��ȯ" << endl;		//���� ���� �߰��� ���� 1�� ���� �� ���

	myQueue.enqueue(9);	//9�� ť ������ �߰���

	myQueue.show();		//���� Stack�� ���¸� ����ȭ��

	return 0;
}