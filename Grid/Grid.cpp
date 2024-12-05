#include <iostream>
#include <cmath>	//floor 연산을 하기 위해서 필요한 라이브러리 입니다.
using namespace std;

class Grid {
	int num_x_bins;	//x축 빈 상자 개수
	int num_y_bins;	//y축 빈 상자 개수
	float x_start;	//격자에 포함된 x의 최솟값
	float x_end;	//격자에 포함된 x의 최댓값
	float x_bin_width;
	float y_start;	//격자에 포함된 y의 최솟값
	float y_end;	//격자에 포함된 y의 최댓값
	float y_bin_width;
	GridPoint** bins; //저장한 좌표들

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
	float x;	//x좌표
	float y;	//y좌표
	
public:
	GridPoint* next;	//다음 점
	GridPoint(float setX, float setY) {
		x = setX;
		y = setY;
		next = nullptr;
	}
};