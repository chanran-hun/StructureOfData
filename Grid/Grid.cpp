#include <iostream>
#include <cmath>
using namespace std;
class GridPoint {
	float x;	//x��ǥ
	float y;	//y��ǥ

public:
	GridPoint* next;	//���� ��

	GridPoint() {
		x = 0;
		y = 0;
		next = nullptr;
	}
	GridPoint(float Xpoint, float Ypoint) {
		x = Xpoint;
		y = Ypoint;
		next = nullptr;
	}
};

class Grid {
	int num_x_bins;	//x�� �� ���� ����
	int num_y_bins;	//y�� �� ���� ����
	float x_start, x_end, x_bin_width;
	float y_start, y_end, y_bin_width;
	GridPoint** bins; //������ ��ǥ��

public:
	Grid(int x_bins, int y_bins, float x_s, float x_e, float y_s, float y_e) : num_x_bins(x_bins), num_y_bins(y_bins), x_start(x_s), 
		x_end(x_e), y_start(y_s), y_end(y_e) {
		x_bin_width = (x_end - x_start) / num_x_bins;
		y_bin_width = (y_end - y_start) / num_y_bins;

		bins = new GridPoint*[num_x_bins];  // ù ��° ���� (x��)
		for (int i = 0; i < num_x_bins; i++) {
			bins[i] = new GridPoint[num_y_bins]();  // �� ��° ���� (y��)
		}
	}
	~Grid() {
		// �޸� ����
		for (int i = 0; i < num_x_bins; ++i) {
			delete[] bins[i];
		}
		delete[] bins;
	}

	bool insertGrid(Grid* g, float x, float y) {
		int xbin = floor((x - x_start) / x_bin_width);
		int ybin = floor((y - y_start) / y_bin_width);

		if (xbin < 0 || num_x_bins <= xbin || ybin < 0 || num_y_bins <= ybin) {
			return false;
		}

		GridPoint* next_point = bins[xbin][ybin];
		bins[xbin][ybin] = GridPoint(x, y);
		bins[xbin][ybin].next = next_point;

		return true;
	}
};