#include <iostream>
using namespace std;

class Queue {
	int front;
	int back;
	int* array;
	int array_size;
	int reset;
public:
	Queue(int n) {	//배열 크기를 입력받고 최선두, 최후방, 출력에 관련한 reset을 0으로 초기화하고 배열크기만큼의 
					//배열 동적할당
		array_size = n;
		front = 0;
		back = 0;
		array = new int[array_size];
		reset = 0;
	}

	void enqueue(int n) {	//새로운 수 추가
		if (back == front && reset != 0) {	//배열에 남은 공간이 전혀 없는 경우
			cout << "더이상은 남은 공간이 없습니다. 삽입실패!" << endl;
			return;
		}

		if (back == array_size) {	//뒤쪽의 공간이 다 찬 경우 -> 앞에 공간이 남았는지 확인함
			cout << "뒷 공간이 꽉 찼습니다!! 앞에 공간이 있는지 확인합니다." << endl;
			if (front != 0) {	//앞쪽에 공간이 있는 경우
				cout << "찾았습니다!! 앞의 남은 공간에 삽입합니다!" << endl;
				back -= array_size;
				reset++;
			}
			else {	//앞쪽에 남은 공간이 없는 경우
				cout << "앞에도 남은 공간이 없습니다. 삽입 실패!" << endl;
				return;
			}
		} 
		this->array[back] = n;	//최후방의 인덱스에 값을 삽입함
		back++;	//최후방 인덱스의 값을 1 증가시킴
		cout << n << "추가 성공!!" << endl;
	}

	int dequeue() {	//가장 먼저 추가된 값을 삭제함과 동시에 그 값을 반환함
		return this->array[this->front++];
	}

	void show() {	//현재의 Stack구조를 가시화 해서 보여줌
		cout << "현재 Queue 상태 가시화 | ";
		if (back > front) {	//평범한 경우의 출력
			for (int i = front; i < back; i++) {
				cout << this->array[i] << " | ";
			}
		}
		else {	//만약 앞의 남은 공간을 활용하기 위해서 back이 초기화 된 경우에는 front부터 끝가지 한번 출력한 후에
			for (int i = front; i < array_size; i++) {	//0부터 back까지를 출력해야함
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
	myQueue.enqueue(1);	//1부터 5까지 큐 구조에 값을 추가함
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);

	myQueue.show();		//현재 Stack의 상태를 가시화하기

	cout << myQueue.dequeue() << "삭제 및 반환" << endl;
	cout << myQueue.dequeue() << "삭제 및 반환" << endl;		//가장 먼저 추가된 값들을 앞에서부터 3개 
	cout << myQueue.dequeue() << "삭제 및 반환" << endl;		//삭제 및 출력

	myQueue.show();		//현재 Stack의 상태를 가시화하기

	myQueue.enqueue(6);	//6부터 8까지 큐 구조에 값을 추가함
	myQueue.enqueue(7);
	myQueue.enqueue(8);

	myQueue.show();		//현재 Stack의 상태를 가시화하기

	cout << myQueue.dequeue() << "삭제 및 반환" << endl;		//가장 먼저 추가된 값을 1개 삭제 및 출력

	myQueue.enqueue(9);	//9를 큐 구조에 추가함

	myQueue.show();		//현재 Stack의 상태를 가시화함

	return 0;
}