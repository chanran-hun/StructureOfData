#include <iostream>
using namespace std;
class Heap {
	int* array;
	int array_size;		//배열의 크기
	int last_index;		//마지막 인덱스
public:
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
};