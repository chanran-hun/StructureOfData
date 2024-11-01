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
	int array_size;		//�迭�� ũ��
	int last_index;		//������ �ε���
public:
	Heap(int size) {
		array = new TaskRecord[size];
		array_size = size;
		last_index = 0;
	}

	void InsertHeap(float value) {
		if (last_index == array_size - 1) {	//ũ��˻�
			TaskRecord* trr = array;
			array_size *= 2;
			array = new TaskRecord[array_size];	//�迭 ũ�� �ι�� �ø���
			for (int i = 1; i < array_size; i++) {
				array[i] = trr[i];
			}
			delete[] trr;
		}

		last_index++;
		array[last_index].priority = value;			//����

		int current = last_index;
		int parent = last_index / 2;	//ũ�� �� �κ�
		while (1 <= parent && isLessThan(array[parent],array[current])){
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
		//�������� ��Ʈ�� ��ȯ�ϰ� �� ũ�� ���
		TaskRecord result = array[1];
		array[1] = array[last_index];
		array[last_index] = TaskRecord();
		last_index--;
		//��Ʈ�� �ùٸ� ��ġ��
		int i = 1;
		while (i <= last_index) {
			int swap = i;
			if (2 * i <= last_index && isLessThan(array[swap] , array[2 * i])) {
				swap = 2 * i;
			}  
			
			if (2 * i + 1 <= last_index && isLessThan(array[swap] , array[2 * i + 1])) {
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

	void show() {
		for (int i = 1; i <= last_index; i++) {
			cout << array[i].priority << endl;
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