#include <iostream>
using namespace std;

class Stack {
	int array_size;	//�迭�� ũ��
	int top;		//�迭���� ���� ū �ε��� ��
	int* array;		//�迭
public:
	Stack(int s) {	//�迭�� ũ�⸦ �޾Ƽ� �����Ҵ� �� top�� �ʱⰪ�� -1�� ����
		array_size = s;
		top = -1;
		array = new int[array_size];
	}

	void push(int value) {	//���ο� ���� �Է�
		if (this->top == this->array_size - 1) {
			cout << "���� �迭�� ������ �����մϴ� �ι�� �ø��ϴ�" << endl;	//�迭�� ������ ������ ��� Ȯ��
			int* tempArray = new int[this->array_size];
			for (int i = 0; i < this->array_size; i++) {
				tempArray[i] = this->array[i];
			}
			delete this->array;
			this->array_size *= 2;
			this->array = new int[this->array_size];
			for (int i = 0; i < this->array_size / 2; i++) {
				this->array[i] = tempArray[i];
			}

		}
		this->top++;
		this->array[this->top] = value;
		cout << value << "��/�� �����߽��ϴ�" << endl;
	}

	int pop() {	//���� ���߿� �߰��� ���� ���� �� ��ȯ
		if (this->top > -1) {
			return this->array[this->top--];
		}
		else {
			cout << "���� �迭�� ����ֽ��ϴ�" << endl;
			return -1;
		}
	}

	void show() {	//���� �迭 ���� ���� �����ִ� �޼���
		cout << "���� Stack�� ��Ȳ ����ȭ :" << " |";
		for (int i = 0; i <= top; i++) {
			cout << array[i] << "|";
		}
		cout << endl;
	}
};

int main() {
	Stack myStack(3);
	
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);	//1���� 8���� �߰�
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	myStack.push(8);

	myStack.show();		//���� Stack�� ��Ȳ ����ȭ

	cout << myStack.pop() << "���� �� ��ȯ" << endl;		//���� �ֱٿ� �߰��� �� 2�� ���� �� ��ȯ
	cout << myStack.pop() << "���� �� ��ȯ" << endl;		//���� �ֱٿ� �߰��� �� 2�� ���� �� ��ȯ

	myStack.show();		//���� Stack�� ��Ȳ ����ȭ

	return 0;
}
//push,pop�� ��� �迭�� ���̿� ���� ���� ����� ����! �̶�, �迭�� Ȯ���� ���� ���̿� ���� ������ �� ->
//����� ū �迭�� �����ϴ°��� �䱸��