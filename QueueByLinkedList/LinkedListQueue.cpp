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
	LinkedListNode* front;	//최전방 노드
	LinkedListNode* back;	//최후방 노드
public:
	Queue() {
		front = nullptr;
		back = nullptr;	//Queue의 생성자, front와 back이 모두 NULL로 초기화 됨
	}

	void enQueue(int value) {	//새로운 값 삽입
		LinkedListNode* node = new LinkedListNode(value);	//노드 생성
		if (this->back == nullptr) {	//만약 노드가 하나라면 그 노드는 front이자 back이 된다
			this->front = node;
			this->back = node;
		}	
		else {
			this->back->next = node;	//뒤에 하나를 추가했다면 그 추가된 노드가 back이 되어야 한다.
			this->back = node;
		}

		cout << value << "삽입 성공!" << endl;
	}

	int deQueue() {
		if (this->front == nullptr) {
			cout << "비어있습니다 deQueue 실패!" << endl;		//queue가 비어있다면 dequeue는 불가능하다
			return -1;
		}
		int value = this->front->data;		//front 노드의 데이터값을 저장해둔다.
		LinkedListNode* temp = this->front;	//현재의 front를 저장해둔다
		this->front = this->front->next;	//front 다음 노드가 front가 되게 한다.
		delete temp;	//기존의 front가 차지하는 메모리 반납
		if (this->front == nullptr) {
			cout << "남은 데이터가 없습니다" << endl;		//만약 dequeue한 값이 queue의 유일한 값이었다면 
			this->back = nullptr;						//back도 NULL이 되어야한다.
		}
		return value;
	}

	void show() {	//현재 queue의 상태를 가시화 한다.
		cout << "Queue의 현재 상태 가시화 :";
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

	myQueue.enQueue(1);	//Queue에 1부터 3까지 삽입한다
	myQueue.enQueue(2);
	myQueue.enQueue(3);
		
	myQueue.show();	//Queue가시화

	cout << myQueue.deQueue() << "삭제 및 반환" << endl;	//최전방 값을 삭제 및 반환한다

	myQueue.show();	//Queue가시화
	
	return 0;
}
//큐는 선입선출이니 먼저 들어온 요청을 먼저 처리해야하는 구조에서 굉장히 유용하다. 
//반면에 스택은 최근 항목을 먼저 처리해야 할 때는 스택이 유용하다. 최근 항목을 처리하고 그 상태에서 팝을 하게 되면 이전
//상태로 돌아오는 식의 방법이 사용될 수 있다.