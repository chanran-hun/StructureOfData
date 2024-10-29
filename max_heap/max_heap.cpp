#include <iostream>
using namespace std;
class Heap {
	int* array;
	int array_size;		//�迭�� ũ��
	int last_index;		//������ �ε���
public:
	void InsertHeap(int value) {
		if (last_index == array_size - 1) {	//ũ��˻�
			int* trr = array;
			array_size *= 2;
			array = new int[array_size];	//�迭 ũ�� �ι�� �ø���
			for (int i = 1; i < array_size; i++) {
				array[i] = trr[i];
			}
			delete trr;
		}

		last_index++;
		array[last_index] = value;			//����

		int current = last_index;
		int parent = last_index / 2;	//ũ�� �� �κ�
		while (1 <= parent && array[parent] < array[current]) {
			int temp = array[parent];
			array[parent] = array[current];
			array[current] = temp;

			current = parent;
			parent /= 2;
		}
	}
};