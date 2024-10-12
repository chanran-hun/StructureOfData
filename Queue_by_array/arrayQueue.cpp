#include <iostream>
using namespace std;

class Queue {
	int front;
	int back;
	int* array;
	int array_size;
	int reset;
	int count; // 현재 큐에 있는 요소의 개수를 추적하는 변수
public:
	Queue(int n) {	//배열 크기를 입력받고 최선두, 최후방, 출력에 관련한 reset을 0으로 초기화하고 배열크기만큼의 
					//배열 동적할당
		array_size = n;
		front = 0;
		back = 0;
		array = new int[array_size];
		reset = 0;
		count = 0; // 큐의 초기 상태는 비어 있음
	}

	~Queue() {
		cout << "소멸자 실행" << endl;
		delete[] array; // 동적 할당된 배열 해제
	}


	void enqueue(int n) {	//새로운 수 추가
		if (count == array_size) { // 배열이 가득 찬 상태
			cout << "삽입 실패: 큐가 가득 찼습니다." << endl;
			return;
		}

		array[back] = n;
		back = (back + 1) % array_size; // back을 모듈로 연산하여 순환 처리
		count++; // 큐에 요소를 하나 추가
		cout << n << " 추가 성공!" << endl;
	}

	bool isEmpty() {
		// count 변수를 사용하여 비어있는지 확인
		return count == 0;
	}

	int dequeue() {
		if (isEmpty()) { // 큐가 비어 있는지 확인
			cout << "삭제 실패: 큐가 비어 있습니다." << endl;
			return -1; // 실제 값을 반환하는 대신 실패를 알려줌
		}

		int value = array[front];
		front = (front + 1) % array_size; // front를 순환 처리
		count--; // 큐에서 요소를 하나 제거
		return value;
	}

	void show() {
		cout << "현재 Queue 상태 가시화 | ";
		if (count == 0) {
			cout << "큐가 비어 있습니다." << endl;
		} else {
			for (int i = 0; i < count; i++) {
				int index = (front + i) % array_size; // front부터 count개의 요소 출력
				cout << array[index] << " | ";
			}
			cout << endl;
		}
	}
};

int main() {
	Queue myQueue = Queue(5);

	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " 삭제 및 반환" << endl;
	} else {
		cout << "큐가 비어 있습니다." << endl;
	}

	myQueue.enqueue(1);	//1부터 5까지 큐 구조에 값을 추가함
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);

	myQueue.show();		//현재 Stack의 상태를 가시화하기

	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " 삭제 및 반환" << endl;
	} else {
		cout << "큐가 비어 있습니다." << endl;
	}
	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " 삭제 및 반환" << endl;//가장 먼저 추가된 값들을 앞에서부터 3개 
	} else {												//삭제 및 출력
		cout << "큐가 비어 있습니다." << endl;
	}		
	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " 삭제 및 반환" << endl;
	} else {
		cout << "큐가 비어 있습니다." << endl;
	}				

	myQueue.show();		//현재 Stack의 상태를 가시화하기

	myQueue.enqueue(6);	//6부터 8까지 큐 구조에 값을 추가함
	myQueue.enqueue(7);
	myQueue.enqueue(8);

	myQueue.show();		//현재 Stack의 상태를 가시화하기

	if (!myQueue.isEmpty()) {
		cout << myQueue.dequeue() << " 삭제 및 반환" << endl;	//가장 먼저 추가된 값을 1개 삭제 및 출력
	} else {
		cout << "큐가 비어 있습니다." << endl;
	}						

	myQueue.enqueue(9);	//9를 큐 구조에 추가함

	myQueue.show();		//현재 Stack의 상태를 가시화함

	myQueue.enqueue(10);	//10를 큐 구조에 추가함

	return 0;
}