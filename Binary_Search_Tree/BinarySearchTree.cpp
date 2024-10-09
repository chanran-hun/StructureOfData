#include <iostream>
using namespace std;

class TreeNode {	//������ ���	
	TreeNode* parent;	//��쿡 ���� �θ� ����Ű�� �����͸� ���� �� ����
public:
	int value;		//��
	TreeNode* left;	//���� �ڽ�
	TreeNode* right;	//������ �ڽ�

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

int main() {

}