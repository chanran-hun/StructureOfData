#include <iostream>
using namespace std;
int LetterToIndex(char letter) {
	return letter - 'a';
}
//Ʈ���� ������ ���
class TrieNode {						
public:
	bool is_entry;						//�ܾ� �Ǻ�
	TrieNode* children[26];				//�ڽĳ���

	TrieNode() {
		is_entry = false;				//�⺻������ ���� ���� ������ �ʱ�ȭ
		for (int i = 0; i < 26; i++) {	//�ڽ� ������ ��� ����ְ� ����
			children[i] = nullptr;
		}
	}
};
//Ʈ������ ����
class Trie {					
public:
	TrieNode* root;				//�ٺ����

	Trie() {
		root = new TrieNode();	//�ٺ��� ������� �� �۵��� ���� �����Ƿ� Ʈ���� ���� ������ �ٺ��� ���� ����
	}
	//Ž���޼���(��)
	TrieNode* TrieNodeSearch(TrieNode* current, string target, int index) {	
		if (index == target.length()) {		//Ž�� �ܾ��� ���̿� ������ �ε����� ������
			if (current->is_entry) {		//�� ������ �ܾ� ���ΰ� ���̶��
				return current;				//���� ��� ��ȯ
			} else {						//�ܾ� ���ΰ� �����̶��
				return nullptr;				//�� ������ ��ȯ
			}
		}//�ܾ��� ���̺��� �ε��� ���� ���� �� 
		char next_letter = target[index];	
		int next_index = LetterToIndex(next_letter);
		TrieNode* next_child = current->children[next_index];	
		if (next_child == nullptr) {		//�ڽ��� ����ִٸ� �� ������ ��ȯ
			return nullptr;
		} else {							//������� �ʴٸ� ���� �ε����� ��� Ž��
			return TrieNodeSearch(next_child, target, index + 1);	
		}
	}
	//Ž�� �޼���
	TrieNode* TrieSearch(string target) {
		return TrieNodeSearch(root, target, 0);
	}
	//���� �޼���(��)
	void InsertTrieNode(TrieNode* current, string new_value, int index) {
		if (index == new_value.length()) {						//�߰����ڿ� �ε��� ���� ������
			current->is_entry = true;							//�ش� ����� ���� ���θ� ������ �ٲ۴�
		} else {												//�ε��� ���� �� ������
			char next_letter = new_value[index];
			int next_index = LetterToIndex(next_letter);
			TrieNode* next_child = current->children[next_index];
			if (next_child == nullptr) {						//�ڽ��� ����ִٸ�
				next_child = new TrieNode();					//���ο� ��� �Ҵ�
				current->children[next_index] = next_child;		//�ڽĿ� ���ο� ��� ����
			}

			InsertTrieNode(next_child, new_value, index + 1);	//�ڽ����� �̵��ؼ� �ٽ� ����
		}
	}
	//���� �޼���
	void InsertTrie(string new_value) {
		InsertTrieNode(root, new_value, 0);
	}
	//���� �޼���(��)
	bool DeleteTrieNode(TrieNode* current, string target, int index) {
		if (index == target.length()) {									//���� �ܾ��� ���̿� �ε����� ���� ��
			if (current->is_entry) {									//���� ����� �ܾ� ���ΰ� ���̶��
				current->is_entry = false;								//�������� �ٲ�
			}
		} else {														//�ε��� ���� �ܾ��� ���̺��� ���� ��
			char next_letter = target[index];
			int next_index = LetterToIndex(next_letter);
			TrieNode* next_child = current->children[next_index];
			if (next_child != nullptr) {								//�ڽ��� ������� �ʴٸ�
				if (DeleteTrieNode(next_child, target, index + 1)) {	//�ڽ��� ������ �Ǵ� �����
					delete next_child;
					current->children[next_index] = nullptr;			//�ڽ��� ���
				}
			}
		}

		if (current->is_entry) {										//���� ����� �ܾ� ���ΰ� ���̶��
			return false;												//����� �Ǵ� ��尡 �ƴ϶�� �˸�
		}

		for (int i = 0; i < 26; i++) {									
			if (current->children[i] != nullptr) {						//�ڽ� �� �ϳ��� ������� ���� �ڽ��� �ִٸ�
				return false;											//����� �Ǵ� ��尡 �ƴ϶�� �˸�
			}
		}

		return true;													//�� ��� �������� �ɷ����� �ʾҴٸ� 
	}																	//����� �Ǵ� ����� �˸�
	//���� �޼���
	void DeleteTrie(string target) {
		DeleteTrieNode(root, target, 0);
	}

};
int main() {
	Trie myTrie = Trie();

	myTrie.InsertTrie("hello");
	myTrie.InsertTrie("world");
	myTrie.InsertTrie("hey");

	TrieNode* hello = myTrie.TrieSearch("hello");
	TrieNode* hey = myTrie.TrieSearch("hey");

	if (hello->is_entry) {
		cout << "hello is valid" << endl;
	}

	if (hey->is_entry) {
		cout << "hey is valid" << endl;
	}

	myTrie.DeleteTrie("hey");

	hey = myTrie.TrieSearch("hey");
	
	TrieNode* test = myTrie.root;
	test = test->children[7];

	if (test != nullptr) {
		cout << "success" << endl;
	}

	test = test->children[4];

	if (test != nullptr) {
		cout << "success" << endl;
	}

	for (int i = 0; i < 26; i++) {
		if (test->children[i] != nullptr) {
			cout << i << endl;
		}
	}

	return 0;
}