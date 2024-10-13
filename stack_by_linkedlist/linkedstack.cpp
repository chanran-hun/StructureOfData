#include <iostream>
using namespace std;
#include <stdexcept>  // 예외 처리에 필요한 헤더

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

	~Stack() {
		while (head != nullptr) {
			LinkedListNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push(int value) {	//새로운 개체 추가
		LinkedListNode* node = new LinkedListNode(value);

		node->next = head;	//head 앞에 새로운 개체 삽입
		head = node;	//head 갱신

		cout << value << "을/를 새로 추가합니다" << endl;
	}

	int pop() {		//최상단 노드 연결해제, 값 반환
		if (this->head == nullptr) {
			throw underflow_error("스택이 비어있습니다.");	//예외처리
		}

		int value = head->data;			//head값 저장
		LinkedListNode* temp = head;	//임시 노드 포인터 생성(메모리 반환을 위한것임)
		head = head->next;	//head 갱신
		delete temp;		//전 head 메모리 반납

		return value;
	}

	void show() {	//Stack의 현 상태 가시화
		cout << "현재 Stack 상태 가시화: ";

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

	try {
		cout << myStack.pop() << " 삭제 및 반환" << endl;
	}
	catch (const underflow_error& e) {
		cerr << e.what() << endl; 
	}

	myStack.push(1);
	myStack.push(2);	//1부터 3 추가
	myStack.push(3);

	myStack.show();		//현재 Stack상태 가시화

	try {
		cout << myStack.pop() << " 삭제 및 반환" << endl;
	}
	catch (const underflow_error& e) {
		cerr << e.what() << endl;
	}

	myStack.show();		//현재 Stack상태 가시화

	return 0;
}     