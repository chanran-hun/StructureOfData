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

	~Stack(){		//�Ҹ���
		delete[] array;
	}

	void push(int value) {	//���ο� ���� �Է�
		if (this->top == this->array_size - 1) {
			cout << "���� �迭�� ������ �����մϴ� �ι�� �ø��ϴ�" << endl;	//�迭�� ������ ������ ��� Ȯ��
			int* tempArray = new int[this->array_size*2];	//ũ�⸦ �ι�� Ȯ��
			for (int i = 0; i < this->array_size; i++) {
				tempArray[i] = this->array[i];
			}

			delete[] this->array;

			this->array = tempArray;
			this->array_size *= 2;
			
			for (int i = 0; i < this->array_size / 2; i++) {
				this->array[i] = tempArray[i];
			}
		}

		this->array[++this->top] = value;
		cout << value << "��/�� �����߽��ϴ�" << endl;
	}

	int pop() {	//���� ���߿� �߰��� ���� ���� �� ��ȯ
		if (this->top > -1) {
			return this->array[this->top--];
		} else {
			throw out_of_range("������ ��� �ֽ��ϴ�.");
		}
	}

	void show() {	//���� �迭 ���� ���� �����ִ� �޼���
		if (top == -1) {
			cout << "���� Stack�� ��� �ֽ��ϴ�." << endl;
		} else {
			cout << "���� Stack�� ��Ȳ ����ȭ: |";
			for (int i = 0; i <= top; i++) {
				cout << array[i] << "|";
			}
			cout << endl;
		}
	}
};

int main() {
	Stack myStack(3);

	try {
		int value = myStack.pop();
		cout << value << "��/�� ���½��ϴ�." << endl;
	}
	catch (const out_of_range& e) {
		cout << "���� �߻�: " << e.what() << endl;
	}

	myStack.show();		//���� Stack�� ��Ȳ ����ȭ

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);	//1���� 8���� �߰�
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	myStack.push(8);

	myStack.show();		//���� Stack�� ��Ȳ ����ȭ

	try {
		int value = myStack.pop();
		cout << value << "��/�� ���½��ϴ�." << endl;
	}
	catch (const out_of_range& e) {
		cout << "���� �߻�: " << e.what() << endl;
	}

	try {
		int value = myStack.pop();
		cout << value << "��/�� ���½��ϴ�." << endl;
	}
	catch (const out_of_range& e) {
		cout << "���� �߻�: " << e.what() << endl;
	}
	myStack.show();		//���� Stack�� ��Ȳ ����ȭ

	return 0;
}
//push,pop�� ��� �迭�� ���̿� ���� ���� ����� ����! �̶�, �迭�� Ȯ���� ���� ���̿� ���� ������ �� ->
//����� ū �迭�� �����ϴ°��� �䱸��