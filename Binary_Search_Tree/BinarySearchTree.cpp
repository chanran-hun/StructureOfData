#include <iostream>
using namespace std;

class TreeNode {	//������ ���	
public:
	int value;		//��
	TreeNode* left;	//���� �ڽ�
	TreeNode* right;	//������ �ڽ�
	TreeNode* parent;	//��쿡 ���� �θ� ����Ű�� �����͸� ���� �� ����

	TreeNode(int v) {
		value = v;		//���� �Է¹޾Ƽ� �ʱ�ȭ
		left = NULL;	//�����͵��� ��������� �ʱ�ȭ	
		right = NULL;
		parent = NULL;
	}
};

//������� ���
TreeNode* FindValue(TreeNode* current, int target) {	//�ѹ��� �˻�� ���� ������ ������ ���� �� �ֱ� ������ ������
	if (current->value == 0) {	//���� ��尡 ������� ��� NULL��ȯ
		return NULL;
	}

	if (current->value == target) {	//��ǩ���� ���� ����� ���̶�� ���� ��带 ��ȯ
		return current;
	}

	if (target < current->value && current->left != NULL) {	//���� ��庸�� ��ǩ���� �۴ٸ� 
		return FindValue(current->left, target);			//���� �ڽ� ���� ��ͽ���
	}

	if (target > current->value && current->right != NULL) {	//���� ��庸�� ��ǩ���� ũ�ٸ�
		return FindValue(current->right, target);				//������ �ڽ� ���� ��ͽ���
	}

	return NULL;	//������ ã�� ���ߴٸ� ��ǩ���� �������� �ʴ°�
}

//�ݺ����� ���
TreeNode* FindValueItr(TreeNode* root, int target) {
	TreeNode* current = root;	//������

	while (current != NULL && current->value != target) {	//������ ��忡 �����ϰų� ��ǥ���� ã���� ����
		if (target < current->value) {						//��ǥ���� ������� ��������
			current = current->left;
		}
		else {												//��ǥ���� Ŭ��� ����������
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

	void InsertNode(TreeNode* current, int new_value) {	//���� ����� ���̿� ���������� ����� ������
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
		if (this->root == NULL || node == NULL) {	//Ʈ���� ��������� NULL��ȯ
			return;
		}

		//���1 : ������� ����
		if (node->left == NULL && node->right == NULL) {
			if (node->parent == NULL) {	//�� ��尡 ������ ����� ���
				this->root = NULL;
			} else if (node->parent->left == node) {	//�ڽ��� �����ڽ��̶�� �θ��� ���� ��� ����
				node->parent->left = NULL;
			} else {
				node->parent->right = NULL;				//������ �ڽ��̶�� �θ��� ������ ��� ����
			}

			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;

			return;
		}

		//���2 : �ڽ��� �ϳ��� ��� ����
		if (node->left == NULL || node->right == NULL) {
			TreeNode* child = node->left;
			if (node->left == NULL) {	//�ڽ��� ����ʿ� �ִ��� Ȯ��
				child = node->right;
			}

			child->parent = node->parent;	//��������� �ڽ��� �°ݽ�Ŵ
			if (node->parent == NULL) {		//�� ��尡 root���ٸ� �ڽ��� root�� ����
				this->root = child;
			} else if (node->parent->left == node) {
				node->parent->left = child;
			} else {
				node->parent->right = child;	//������ ���� �ڽ��̾����� ������ �ڽ��̾������� ���� �˸°� �°�
			}

			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;
		
			return;
		}

		//���3 : �ڽ��� ���� ��� ����
		TreeNode* successor = node->right;

		while (successor->left != NULL) {	//�ļ��� Ž��
			successor = successor->left;
		}

		RemoveTreeNode(successor);		//�ļ��� ��������

		if (node->parent == NULL) {		//����� ��ġ�� �ļ��� ����
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

		// ������ �ڽ� ��� (���������� �� ���� ������ �� ��)
		PrintTree(node->right, space);

		// ���� ��� ���
		cout << endl;
		for (int i = level_space; i < space; i++)
			cout << " ";  // ������ ���
		cout << node->value << "\n";  // ����� ���� ���

		// ���� �ڽ� ��� (�������� ������ �� ��)
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

	tree.Display();  // Ʈ�� ���

	return 0;

}