#include <iostream>
using namespace std;

class TreeNode {	//각각의 노드	
public:
	int value;		//값
	TreeNode* left;	//왼쪽 자식
	TreeNode* right;	//오른쪽 자식
	TreeNode* parent;	//경우에 따라서 부모를 가리키는 포인터를 가질 수 있음

	TreeNode(int v) {
		value = v;		//값을 입력받아서 초기화
		left = NULL;	//포인터들은 빈공간으로 초기화	
		right = NULL;
		parent = NULL;
	}
};

//재귀적인 방법
TreeNode* FindValue(TreeNode* current, int target) {	//한번의 검사로 남은 공간의 절반을 날릴 수 있기 때문에 유용함
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

	return NULL;	//끝까지 찾지 못했다면 목푯값은 존재하지 않는것
}

//반복적인 방법
TreeNode* FindValueItr(TreeNode* root, int target) {
	TreeNode* current = root;	//시작점

	while (current != NULL && current->value != target) {	//마지막 노드에 도달하거나 목표물을 찾으면 종료
		if (target < current->value) {						//목표물이 작을경우 왼쪽으로
			current = current->left;
		}
		else {												//목표물이 클경우 오른쪽으로
			current = current->right;
		}
	}

	return current;
}

class BinarySearchTree {
	TreeNode* root;
public:
	BinarySearchTree() {
		root = NULL;
	}

	TreeNode* FindTreeNode(int target) {
		if (this->root == NULL) {
			return NULL;
		}

		return FindValue(this->root, target);
	}

	void InsertNode(TreeNode* current, int new_value) {	//삽입 비용은 깊이에 선형적으로 비례해 증가함
		if (new_value < current->value) {
			if (current->left == NULL) {
				current->left = new TreeNode(new_value);
				current->left->parent = current;
			}
			else {
				InsertNode(current->left, new_value);
			}
		}
		else {
			if (current->right == NULL) {
				current->right = new TreeNode(new_value);
				current->right->parent = current;
			}
			else {
				InsertNode(current->right, new_value);
			}
		}
	}

	void InsertTreeNode(int new_value) {
		if (root == NULL) {	
			root = new TreeNode(new_value);
		}
		else {
			InsertNode(root, new_value);
		}
	}

	void RemoveTreeNode(TreeNode* node) {
		if (this->root == NULL || node == NULL) {	//트리가 비어있을시 NULL반환
			return;
		}

		//경우1 : 리프노드 제거
		if (node->left == NULL && node->right == NULL) {
			if (node->parent == NULL) {	//이 노드가 유일한 노드일 경우
				this->root = NULL;
			} else if (node->parent->left == node) {	//자신이 왼쪽자식이라면 부모의 왼쪽 노드 삭제
				node->parent->left = NULL;
			} else {
				node->parent->right = NULL;				//오른쪽 자식이라면 부모의 오른쪽 노드 삭제
			}

			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;

			return;
		}

		//경우2 : 자식이 하나인 노드 제거
		if (node->left == NULL || node->right == NULL) {
			TreeNode* child = node->left;
			if (node->left == NULL) {	//자식이 어느쪽에 있는지 확인
				child = node->right;
			}

			child->parent = node->parent;	//삭제노드의 자식을 승격시킴
			if (node->parent == NULL) {		//이 노드가 root였다면 자식을 root로 갱신
				this->root = child;
			} else if (node->parent->left == node) {
				node->parent->left = child;
			} else {
				node->parent->right = child;	//기존이 왼쪽 자식이었는지 오른쪽 자식이었는지에 따라 알맞게 승격
			}

			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;
		
			return;
		}

		//경우3 : 자식이 둘인 노드 제거
		TreeNode* successor = node->right;

		while (successor->left != NULL) {	//후속자 탐색
			successor = successor->left;
		}

		RemoveTreeNode(successor);		//후속자 연결해제

		if (node->parent == NULL) {		//노드의 위치에 후속자 삽입
			root = successor;
		} else if (node->parent->left == node) {
			node->parent->left = successor;
		} else {
			node->parent->right = successor;
		}

		successor->parent = node->parent;

		successor->left = node->left;
		node->left->parent = successor;

		successor->right = node->right;
		if (node->right != NULL) {
			node->right->parent = successor;
		}

		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
	}

	void PrintTree(TreeNode* node, int space = 0, int level_space = 6) {
		if (node == NULL)
			return;

		space += level_space;

		// 오른쪽 자식 출력 (오른쪽으로 더 많은 여백을 준 후)
		PrintTree(node->right, space);

		// 현재 노드 출력
		cout << endl;
		for (int i = level_space; i < space; i++)
			cout << " ";  // 여백을 출력
		cout << node->value << "\n";  // 노드의 값을 출력

		// 왼쪽 자식 출력 (왼쪽으로 여백을 준 후)
		PrintTree(node->left, space);
	}


	void Display() {
		PrintTree(root);
	}

};


int main() {
	BinarySearchTree tree;

	tree.InsertTreeNode(8);
	tree.InsertTreeNode(3);
	tree.InsertTreeNode(10);
	tree.InsertTreeNode(1);
	tree.InsertTreeNode(6);
	tree.InsertTreeNode(14);
	tree.InsertTreeNode(4);
	tree.InsertTreeNode(7);
	tree.InsertTreeNode(13);

	tree.Display();  // 트리 출력

	return 0;

}