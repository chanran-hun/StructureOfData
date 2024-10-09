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
	TreeNode* FindTreeNode(int target) {
		if (this->root == NULL) {
			return;
		}

		return FindValue(this->root, target);
	}

	void InsertNode(TreeNode* current, int new_value) {	//���� ����� ���̿� ���������� ����� ������
		if (new_value == current->value) {
			return;
		}

		if (new_value < current->value) {
			if (current->left == NULL) {
				InsertNode(current->left, new_value);
			}
			else {
				current->left = new TreeNode(new_value);
				current->left->parent = current;
			}
		}
		else {
			if (current->right != NULL) {
				InsertNode(current->right, new_value);
			}
			else {
				current->right = new TreeNode(new_value);
				current->right->parent = current;
			}
		}
	}

	void InsertTreeNode(int new_value) {
		if (this->root == NULL) {
			this->root = new TreeNode(new_value);
		}
		else {
			InsertNode(this->root, new_value);
		}
	}

};


int main() {

}