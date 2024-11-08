#include <iostream>
#include <vector>
using namespace std;
float distance(float a, float b) {
	if ((a - b) > 0) {
		return a - b;
	} else {
		return b - a;
	}
}

float LinearScanClosestNeighbor(const vector<float>& array, float target) {
	int N = array.size();

	if (N == 0) {
		return 0;
	}

	float candidate = array[0];
	float closest_distance = distance(target, candidate);

	int i = 1;
	while (i < N) {
		float current_distance = distance(target, array[i]);

		if (current_distance < closest_distance) {
			closest_distance = current_distance;
			candidate = array[i];
		}
		i++;
	}

	return candidate;
}

int main() {
	vector<float> array(5);
	array.push_back(1.1);
	array.push_back(1.2);
	array.push_back(2.3);
	array.push_back(4.0);
	array.push_back(5.5);

	cout << LinearScanClosestNeighbor(array, 2.3);

	return 0;
}