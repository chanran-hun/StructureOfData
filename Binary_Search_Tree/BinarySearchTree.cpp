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
	//재귀적인 탐색
	TreeNode* FindValue(TreeNode* current, int target) {
		//경우 1 : 찾는 노드가 현재 노드와 같을경우 : 현재 노드 반환
		if (current == nullptr || current->value == target) {
			return current;
		}
		//경우 2 : 찾는 노드가 현재 노드보다 작을 경우 
		if (target < current->value) {
			return FindValue(current->left, target);	//왼쪽 노드를 대상으로 재귀실행
		}
		//경우 3 : 찾는 노드가 현재 노드보다 클 경우
		return FindValue(current->right, target);		//오른쪽 노드를 대상으로 재귀실행	
	}
	//재귀적인 탐색을 이용하기 위한 메서드
	TreeNode* FindTreeNode(int target) {
		if (this->root == nullptr) {
			return nullptr;
		}

		return FindValue(this->root, target);
	}
	//반복적인 방법
	TreeNode* FindValueItr(int target) {
		TreeNode* current = root;	//임시 노드를 만들어내고 트리의 root를 저장한다.
		//반복문 실행 : 노드의 끝까지 탐색했으나 값을 찾지 못하거나 값을 때 까지 반복탐색
		while (current != nullptr && current->value != target) {
			if (target < current->value) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
		//끝까지 값을 찾아내지 못하거나 값을 찾아냈을 경우 그 값을 반환
		return current;
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

	tree.RemoveTreeNode(tree.FindValueItr(13));	//리프노드 제거
	tree.RemoveTreeNode(tree.FindValueItr(10));	//자식이 하나인 노드 제거
	tree.RemoveTreeNode(tree.FindValueItr(6));	//자식이 두개인 노드 제거

	tree.Display();  // 트리 출력

	return 0;

}