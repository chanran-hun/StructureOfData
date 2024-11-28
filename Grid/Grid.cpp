#include <iostream>
using namespace std;

class Grid {
	int num_x_bins;	//x축 빈 상자 개수
	int num_y_bins;	//y축 빈 상자 개수
	float x_start;	//격자에 포함된 x의 최솟값
	float x_end;	//격자에 포함된 x의 최댓값
	float x_bin_width = (x_end - x_start) / num_x_bins;	//x축 빈 상자의 x길이
	float y_start;	//격자에 포함된 y의 최솟값
	float y_end;	//격자에 포함된 y의 최댓값
	float y_bin_width = (y_end - y_start) / num_y_bins;	//y축 빈 상자의 y길이
	Matrix of GridPoints : bins //저장한 좌표들
};

class GridPoint {
	float x;	//x좌표
	float y;	//y좌표
	GridPoint* next;	//다음 점
};