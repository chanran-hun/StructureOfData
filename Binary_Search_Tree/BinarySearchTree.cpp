#include <iostream>
using namespace std;

class TreeNode {	//각각의 노드	
	TreeNode* parent;	//경우에 따라서 부모를 가리키는 포인터를 가질 수 있음
public:
	int value;		//값
	TreeNode* left;	//왼쪽 자식
	TreeNode* right;	//오른쪽 자식

	TreeNode(int v) {
		value = v;		//값을 입력받아서 초기화
		left = NULL;	//포인터들은 빈공간으로 초기화	
		right = NULL;
		parent = NULL;
	}

};

TreeNode* FindValue(TreeNode* current, int target) {
	if (current->value == 0) {	//현재 노드가 비어있을 경우 NULL반환
		return NULL;
	}

	if (current->value == target) {	//목푯값이 현재 노드의 값이라면 현재 노드를 반환
		return current;
	}

	if (target < current->value && current->left != NULL) {	//현재 노드보다 목푯값이 작다면 
		return FindValue(current->left, target);			//왼쪽 자식 노드로 재귀실행
	}

	if (target > current->value && current->right != NULL) {	//현재 노드보다 목푯값이 크다면
		return FindValue(current->right, target);				//오른쪽 자식 노드로 재귀실행
	}

	return NULL;
}

int main() {

}