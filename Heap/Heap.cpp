#include <iostream>
using namespace std;
class TaskRecord {
	string taskname;
	string instructions;
	string PersonWhoWilYellIfThisIsNotDone;
	bool completed;
public:
	float priority;
	TaskRecord() {
		priority = 0;
		taskname = "";
		instructions = "";
		PersonWhoWilYellIfThisIsNotDone = "";
		completed = false;
	}
};

bool isLessThan(TaskRecord a, TaskRecord b) {
	return a.priority < b.priority;
}

class Heap {
	TaskRecord* array;
	int array_size;		//배열의 크기
public:
	int last_index;		//마지막 인덱스
	Heap(int size) {
		array = new TaskRecord[size];
		array_size = size;
		last_index = 0;
	}

	void InsertMaxHeap(float value) {
		if (last_index == array_size - 1) {	//크기검사
			TaskRecord* trr = array;
			array_size *= 2;
			array = new TaskRecord[array_size];	//배열 크기 두배로 늘리기
			for (int i = 1; i < array_size; i++) {
				array[i] = trr[i];
			}
			delete[] trr;
		}

		last_index++;
		array[last_index].priority = value;			//삽입

		int current = last_index;
		int parent = last_index / 2;	//크기 비교 부분
		while (1 <= parent && isLessThan(array[parent],array[current])){
			TaskRecord temp = array[parent];
			array[parent] = array[current];
			array[current] = temp;

			current = parent;
			parent /= 2;
		}
	}

	void InsertMinHeap(float value) {
		if (last_index == array_size - 1) {	//크기검사
			TaskRecord* trr = array;
			array_size *= 2;
			array = new TaskRecord[array_size];	//배열 크기 두배로 늘리기
			for (int i = 1; i < array_size; i++) {
				array[i] = trr[i];
			}
			delete[] trr;
		}

		last_index++;
		array[last_index].priority = value;			//삽입

		int current = last_index;
		int parent = last_index / 2;	//크기 비교 부분
		while (1 <= parent && isLessThan(array[current], array[parent])) {
			TaskRecord temp = array[parent];
			array[parent] = array[current];
			array[current] = temp;

			current = parent;
			parent /= 2;
		}
	}

	TaskRecord removeMaxHeap() {
		if (last_index == 0) {
			return TaskRecord();
		}
		//마지막과 루트를 교환하고 힙 크기 축소
		TaskRecord result = array[1];
		array[1] = array[last_index];
		array[last_index] = TaskRecord();
		last_index--;
		//루트를 올바른 위치로
		int i = 1;
		while (i <= last_index) {
			int swap = i;
			if (2 * i <= last_index && isLessThan(array[swap], array[2 * i])) {
				swap = 2 * i;
			}

			if (2 * i + 1 <= last_index && isLessThan(array[swap], array[2 * i + 1])) {
				swap = 2 * i + 1;
			}

			if (i != swap) {
				TaskRecord temp = array[i];
				array[i] = array[swap];
				array[swap] = temp;
				i = swap;
			} else {
				break;
			}

		}
		return result;
	}

	TaskRecord removeMinHeap() {
		if (last_index == 0) {
			return TaskRecord();
		}
		//마지막과 루트를 교환하고 힙 크기 축소
		TaskRecord result = array[1];
		array[1] = array[last_index];
		array[last_index] = TaskRecord();
		last_index--;
		//루트를 올바른 위치로
		int i = 1;
		while (i <= last_index) {
			int swap = i;
			if (2 * i <= last_index && isLessThan(array[2 * i] , array[swap])) {
				swap = 2 * i;
			}  
			
			if (2 * i + 1 <= last_index && isLessThan(array[2 * i + 1] , array[swap])) {
				swap = 2 * i + 1;
			}

			if (i != swap) {
				TaskRecord temp = array[i];
				array[i] = array[swap];
				array[swap] = temp;
				i = swap;
			} else {
				break;
			}

		}
		return result;
	}

	void updateValue(int index, float value) {
		TaskRecord old_value = array[index];
		array[index].priority = value;

		int i = index;
		if (old_value.priority < value) {
			while (1 < i) {
				int swap = i;
				if (1 <= i / 2 && isLessThan(array[i / 2], array[swap])) {
					swap = i / 2;
				}

				if (i != swap) {
					TaskRecord temp = array[i];
					array[i] = array[swap];
					array[swap] = temp;
					i = swap;
				} else {
					break;
				}

			}
			//array[index]를 힙의 위쪽으로 올려야할 것 같음
		} else {
			while ( i < last_index) {
				int swap = i;
				if (i * 2 <= last_index && isLessThan(array[swap], array[i * 2])) {
					swap = i * 2;
				}
				if (i * 2 + 1 <= last_index && isLessThan(array[swap], array[i * 2 + 1])) {
					swap = i * 2 + 1;
				}

				if (i != swap) {
					TaskRecord temp = array[i];
					array[i] = array[swap];
					array[swap] = temp;
					i = swap;
				} else {
					break;
				}

			}
			//array[index]를 힙의 아래쪽으로 내려야할 것 같음
		}
	}

	void show() {
		for (int i = 1; i <= last_index; i++) {
			cout << array[i].priority << endl;
		}
	}
};

TaskRecord* sortMaxHeap(TaskRecord* unsorted, int size) {
	Heap* tmp_heap = new Heap(size);
	TaskRecord* result = new TaskRecord[size];

	int j = 0;
	while (j < size) {
		tmp_heap->InsertMaxHeap(unsorted[j].priority);
		j++;
	}

	j = 0;
	while (j < size) {
		result[j] = tmp_heap->removeMaxHeap();
		j++;
	}

	return result;
}

TaskRecord* sortMinHeap(TaskRecord* unsorted, int size) {
	Heap* tmp_heap = new Heap(size);
	TaskRecord* result = new TaskRecord[size];

	int j = 0;
	while (j < size) {
		tmp_heap->InsertMinHeap(unsorted[j].priority);
		j++;
	}

	j = 0;
	while (j < size) {
		result[j] = tmp_heap->removeMinHeap();
		j++;
	}

	return result;
}

int main() {
	return 0;
}