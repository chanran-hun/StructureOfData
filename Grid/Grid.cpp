#include <iostream>
using namespace std;

class Grid {
	int num_x_bins;	//x�� �� ���� ����
	int num_y_bins;	//y�� �� ���� ����
	float x_start;	//���ڿ� ���Ե� x�� �ּڰ�
	float x_end;	//���ڿ� ���Ե� x�� �ִ�
	float x_bin_width = (x_end - x_start) / num_x_bins;	//x�� �� ������ x����
	float y_start;	//���ڿ� ���Ե� y�� �ּڰ�
	float y_end;	//���ڿ� ���Ե� y�� �ִ�
	float y_bin_width = (y_end - y_start) / num_y_bins;	//y�� �� ������ y����
	Matrix of GridPoints : bins //������ ��ǥ��
};

class GridPoint {
	float x;	//x��ǥ
	float y;	//y��ǥ
	GridPoint* next;	//���� ��
};