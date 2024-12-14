#include <iostream>
#include <cmath>	//floor ����, abs ������ �ϱ� ���ؼ� �ʿ��� ���̺귯�� �Դϴ�.
#define THRESHOLD 5.0
using namespace std;

bool approx_equal(float x1, float y1, float x2, float y2) {	//��ó�� ���� ã�� ���� ����� �Լ� �Դϴ�.
	if (abs(x1 - x2) > THRESHOLD) {
		return false;
	}
	if (abs(y1 - y2) > THRESHOLD) {
		return false;
	}
	return true;
}

class Grid {
	int num_x_bins;	//x�� �� ���� ����
	int num_y_bins;	//y�� �� ���� ����
	float x_start, x_end, x_bin_width;
	float y_start, y_end, y_bin_width;
	GridPoint** bins; //������ ��ǥ��

public:
	bool insertGrid(float x, float y) {
		int xbin = floor((x - x_start) / x_bin_width);
		int ybin = floor((y - y_start) / y_bin_width);

		if (xbin < 0 || num_x_bins <= xbin || ybin < 0 || num_y_bins <= ybin) {
			return false;
		}

		GridPoint next_point = bins[xbin][ybin];
		bins[xbin][ybin] = GridPoint(x, y);
		bins[xbin][ybin].next = &next_point;

		return true;
	}
};

class GridPoint {
	float x;	//x��ǥ
	float y;	//y��ǥ

public:
	GridPoint* next;	//���� ��
	GridPoint(float setX, float setY) {
		x = setX;
		y = setY;
		next = nullptr;
	}
};