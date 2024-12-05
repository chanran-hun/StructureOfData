#include <iostream>
#include <cmath>	//floor ������ �ϱ� ���ؼ� �ʿ��� ���̺귯�� �Դϴ�.
using namespace std;

class Grid {
	int num_x_bins;	//x�� �� ���� ����
	int num_y_bins;	//y�� �� ���� ����
	float x_start;	//���ڿ� ���Ե� x�� �ּڰ�
	float x_end;	//���ڿ� ���Ե� x�� �ִ�
	float x_bin_width;
	float y_start;	//���ڿ� ���Ե� y�� �ּڰ�
	float y_end;	//���ڿ� ���Ե� y�� �ִ�
	float y_bin_width;
	GridPoint** bins; //������ ��ǥ��

public:
	bool insertGrid(float x, float y) {
		int xbin = floor((x - x_start) / x_bin_width);
		int ybin = floor((y - y_start) / y_bin_width);

		if (xbin < 0 || num_x_bins <= xbin) {
			return false;
		}
		if (ybin < 0 || num_y_bins <= ybin) {
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