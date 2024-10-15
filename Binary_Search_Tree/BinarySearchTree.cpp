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
		left = nullptr;	//포인터들은 빈공간으로 초기화	
		right = nullptr;
		parent = nullptr;
	}
};

//재귀적인 방법
TreeNode* FindValue(TreeNode* current, int target) {	//한번의 검사로 남은 공간의 절반을 날릴 수 있기 때문에 유용함
	if (current == nullptr || current->value == target) {	//목푯값이 현재 노드의 값이라면 현재 노드를 반환
		return current;
	}

	if (target < current->value) {	//현재 노드보다 목푯값이 작다면 
		return FindValue(current->left, target);			//왼쪽 자식 노드로 재귀실행
	}

	return FindValue(current->right, target);
}

//반복적인 방법
TreeNode* FindValueItr(TreeNode* root, int target) {
	TreeNode* current = root;	//시작점

	while (current != nullptr && current->value != target) {	//마지막 노드에 도달하거나 목표물을 찾으면 종료
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
		root = nullptr;
	}

	~BinarySearchTree() {
		DeleteTree(root);
	}

	void DeleteTree(TreeNode* node) {
		if (node != nullptr) {
			DeleteTree(node->left);
			DeleteTree(node->right);
			delete node;
		}
	}

	TreeNode* FindTreeNode(int target) {
		if (this->root == nullptr) {
			return nullptr;
		}

		return FindValue(this->root, target);
	}

	void InsertNode(TreeNode* current, int new_value) {	//삽입 비용은 깊이에 선형적으로 비례해 증가함
		if (new_value == current->value) {
			//중복된 값은 추가 하지 않음
			return;
		}

		if (new_value < current->value) {
			if (current->left == nullptr) {
				current->left = new TreeNode(new_value);
				current->left->parent = current;
			}
			else {
				InsertNode(current->left, new_value);
			}
		}
		else {
			if (current->right == nullptr) {
				current->right = new TreeNode(new_value);
				current->right->parent = current;
			}
			else {
				InsertNode(current->right, new_value);
			}
		}
	}

	void InsertTreeNode(int new_value) {
		if (root == nullptr) {	
			root = new TreeNode(new_value);
		}
		else {
			InsertNode(root, new_value);
		}
	}

	void RemoveTreeNode(TreeNode* node) {
		if (root == nullptr || node == nullptr) {	//트리가 비어있을시 종료
			return;
		}

		//경우1 : 리프노드 제거
		if (node->left == nullptr && node->right == nullptr) {
			if (node->parent == nullptr) {		//이 노드가 유일한 노드일 경우
				root = nullptr;
			} else if (node->parent->left == node) {	//자신이 왼쪽자식이라면 부모의 왼쪽 노드 삭제
				node->parent->left = nullptr;
			} else {
				node->parent->right = nullptr;				//오른쪽 자식이라면 부모의 오른쪽 노드 삭제
			}

			delete node;
			return;
		}

		//경우2 : 자식이 하나인 노드 제거
		if (node->left == nullptr || node->right == nullptr) {
			TreeNode* child = (node->left != nullptr) ? node->left : node->right;	//자식이 어느쪽인지

			child->parent = node->parent;	//삭제노드의 자식을 승격시킴
			if (node->parent == nullptr) {		//이 노드가 root였다면 자식을 root로 갱신
				this->root = child;
			} else if (node->parent->left == node) {
				node->parent->left = child;
			} else {
				node->parent->right = child;	//기존이 왼쪽 자식이었는지 오른쪽 자식이었는지에 따라 알맞게 승격
			}

			delete node;
			return;
		}

		//경우3 : 자식이 둘인 노드 제거
		TreeNode* successor = node->right;

		while (successor->left != nullptr) {	//후속자 탐색
			successor = successor->left;
		}

		// 후속자를 삭제합니다.
		if (successor->parent != node) { // successor가 node의 자식이 아닌 경우
			// successor의 오른쪽 자식을 successor의 부모와 연결
			successor->parent->left = successor->right;
			if (successor->right != nullptr) {
				successor->right->parent = successor->parent;
			}
			successor->right = node->right; // successor의 오른쪽을 node의 오른쪽으로
			if (successor->right != nullptr) {
				successor->right->parent = successor; // 부모 연결
			}
		}

		if (node->parent == nullptr) {		//노드의 위치에 후속자 삽입
			root = successor;
		} else if (node->parent->left == node) {
			node->parent->left = successor;
		} else {
			node->parent->right = successor;
		}

		successor->parent = node->parent;
		successor->left = node->left;
		node->left->parent = successor;

		if (node->right != successor) {
			successor->right = node->right;
			if (node->right != nullptr) {
				node->right->parent = successor;
			}
		}

		delete node;
	}

	void PrintTree(TreeNode* node, int space = 0, int level_space = 6) {
		if (node == nullptr)
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
	tree.InsertTreeNode(1);		//트리구축
	tree.InsertTreeNode(6);
	tree.InsertTreeNode(14);
	tree.InsertTreeNode(4);
	tree.InsertTreeNode(7);
	tree.InsertTreeNode(13);

	tree.RemoveTreeNode(tree.FindTreeNode(13));	//리프노드 제거
	tree.RemoveTreeNode(tree.FindTreeNode(10));	//자식이 하나인 노드 제거
	tree.RemoveTreeNode(tree.FindTreeNode(6));	//자식이 두개인 노드 제거

	tree.Display();  // 트리 출력

	return 0;

}