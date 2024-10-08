#include <iostream>
using namespace std;

class LinkedListNode {
public:
	int data;				//노드에 들어간 값
	LinkedListNode* next;	//다음 노드를 가리킴
	LinkedListNode(int value) {	//노드의 생성자, 넣은 정수로 data를 초기화 하고 next는 NULL로 초기화
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
		back = nullptr;	//Queue의 생성자, front와 back이 모두 NULL로 초기화 됨
	}

	void enQueue(int value) {	//새로운 값 삽입
		LinkedListNode* node = new LinkedListNode(value);	//노드 생성
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
			cout << "비어있습니다 deQueue 실패!" << endl;
			return -1;
		}
		int value = this->front->data;
		this->front = this->front->next;
		if (this->front == nullptr) {
			cout << "남은 데이터가 없습니다" << endl;
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

	cout << "deQueue 값:" << myQueue.deQueue() << endl;

	myQueue.show();
	
	return 0;
}
//큐는 선입선출이니 먼저 들어온 요청을 먼저 처리해야하는 구조에서 굉장히 유용하다. 
//반면에 스택은 최근 항목을 먼저 처리해야 할 때는 스택이 유용하다. 최근 항목을 처리하고 그 상태에서 팝을 하게 되면 이전
//상태로 돌아오는 식의 방법이 사용될 수 있다.