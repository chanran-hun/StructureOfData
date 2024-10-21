#include <iostream>
using namespace std;
char LetterToIndex(char letter) {
	return letter - 'a';
}

class TrieNode {
public:
	bool is_entry;			//�ܾ� �Ǻ�
	TrieNode* children[26];	//�ڽĳ���
};

class Trie {
public:
	TrieNode* root;			//�ٺ����

	TrieNode* TrieNodeSearch(TrieNode* current, string target, int index) {
		if (index == target.length()) {
			if (current->is_entry) {
				return current;
			} else {
				return nullptr;
			}
		}

		char next_letter = target[index];
		int next_index = LetterToIndex(next_letter);
		TrieNode* next_child = current->children[next_index];
		if (next_child == nullptr) {
			return nullptr;
		} else {
			TrieNodeSearch(current, target, index + 1);
		}
	}

	TrieNode* TrieSearch(Trie* trie, string target) {
		return TrieNodeSearch(trie->root, target, 0);
	}
};
int main() {

}