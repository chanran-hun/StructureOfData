#include <iostream>
using namespace std;

class Stack {
	int array_size;	//배열의 크기
	int top;		//배열에서 가장 큰 인덱스 값
	int* array;		//배열
public:
	Stack(int s) {	//배열의 크기를 받아서 동적할당 후 top의 초기값을 -1로 설정
		array_size = s;
		top = -1;
		array = new int[array_size];
	}

	void push(int value) {	//새로운 수를 입력
		if (this->top == this->array_size - 1) {
			cout << "현재 배열은 공간이 부족합니다 두배로 늘립니다" << endl;	//배열의 공간이 부족할 경우 확장
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
		cout << value << "을/를 삽입했습니다" << endl;
	}

	int pop() {	//가장 나중에 추가된 값을 삭제 및 반환
		if (this->top > -1) {
			return this->array[this->top--];
		}
		else {
			cout << "현재 배열이 비어있습니다" << endl;
			return -1;
		}
	}

	void show() {	//현재 배열 안의 값을 보여주는 메서드
		cout << "현재 Stack의 상황 가시화 :" << " |";
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
	myStack.push(4);	//1부터 8까지 추가
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	myStack.push(8);

	myStack.show();		//현재 Stack의 상황 가시화

	cout << myStack.pop() << "삭제 및 반환" << endl;		//가장 최근에 추가된 값 2개 삭제 및 반환
	cout << myStack.pop() << "삭제 및 반환" << endl;		//가장 최근에 추가된 값 2개 삭제 및 반환

	myStack.show();		//현재 Stack의 상황 가시화

	return 0;
}
//push,pop의 경우 배열의 길이와 관계 없이 비용이 동일! 이때, 배열을 확장할 때는 길이에 따라 영향이 감 ->
//충분히 큰 배열을 선언하는것이 요구됨