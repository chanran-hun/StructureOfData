#include <iostream>
using namespace std;
class Heap {
	int* array;
	int array_size;		//배열의 크기
	int last_index;		//마지막 인덱스
public:
	Heap(int size) {
		array = new int[size];
		array_size = size;
		last_index = 0;
	}

	void InsertHeap(int value) {
		if (last_index == array_size - 1) {	//크기검사
			int* trr = array;
			array_size *= 2;
			array = new int[array_size];	//배열 크기 두배로 늘리기
			for (int i = 1; i < array_size; i++) {
				array[i] = trr[i];
			}
			delete trr;
		}

		last_index++;
		array[last_index] = value;			//삽입

		int current = last_index;
		int parent = last_index / 2;	//크기 비교 부분
		while (1 <= parent && array[parent] < array[current]) {
			int temp = array[parent];
			array[parent] = array[current];
			array[current] = temp;

			current = parent;
			parent /= 2;
		}
	}

	int removeMaxHeap() {
		if (last_index == 0) {
			return -1;
		}
		//마지막과 루트를 교환하고 힙 크기 축소
		int result = array[1];
		array[1] = array[last_index];
		array[last_index] = 0;
		last_index--;
		//루트를 올바른 위치로
		int i = 1;
		while (i <= last_index) {
			int swap = i;
			if (2 * i <= last_index && (array[swap] < array[2 * i])) {
				swap = 2 * i;
			}  
			
			if (2 * i + 1 <= last_index && (array[swap] < array[2 * i + 1])) {
				swap = 2 * i + 1;
			}

			if (i != swap) {
				int temp = array[i];
				array[i] = array[swap];
				array[swap] = temp;
				i = swap;
			} else {
				break;
			}

			return result;
		}
	}

	void show() {
		for (int i = 1; i <= last_index; i++) {
			cout << array[i] << endl;
		}
	}
};

int main() {
	Heap myHeap = Heap(5);

	myHeap.InsertHeap(90);
	myHeap.InsertHeap(40);
	myHeap.InsertHeap(50);

	myHeap.show();

	myHeap.removeMaxHeap();

	myHeap.show();

	return 0;
}