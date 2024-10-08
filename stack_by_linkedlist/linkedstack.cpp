#include <iostream>
using namespace std;

class LinkedListNode {	//노드 클래스, 데이터 값을 가지고 다음 노드를 가리킨다.
public:
	int data;
	LinkedListNode* next;

	LinkedListNode(int d) {	//데이터값을 받아서 초기화 시키고 포인터는 NULL을 가리키게 초기화
		data = d;
		next = nullptr;
	}
};

class Stack {	//스택 클래스
public:
	LinkedListNode* head;	//Linked List의 head

	Stack() {
		head = nullptr;		//head를 NULL로 초기화
	}

	void push(int value) {	//새로운 개체 추가
		LinkedListNode* node = new LinkedListNode(value);
		node->next = this->head;	//head 앞에 새로운 개체 삽입
		this->head = node;	//head 갱신
		cout << value << "을/를 새로 추가합니다" << endl;
	}

	int pop() {		//최상단 노드 연결해제, 값 반환
		int value = 0;
		if (this->head != nullptr) {
			value = this->head->data;		//최상단 값 다른곳에 옮겨담기
			this->head = this->head->next;	//head 갱신
		}
		return value;	//기존의 최상단 값 반환
	}

	void show() {	//Stack의 현 상태 가시화
		cout << "Stack 가시화: ";
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
	cout << "pop 실행! 최상단 값: " << myStack.pop() << endl;
	myStack.show();

	return 0;
}     