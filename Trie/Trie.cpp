#include <iostream>
using namespace std;
int LetterToIndex(char letter) {
	return letter - 'a';
}

class TrieNode {
public:
	bool is_entry;			//단어 판별
	TrieNode* children[26];	//자식노드들

	TrieNode() {
		is_entry = false;
		for (int i = 0; i < 26; i++) {
			children[i] = nullptr;
		}
	}
};

class Trie {
public:
	TrieNode* root;			//근본노드

	Trie() {
		root = new TrieNode();
	}

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
			return TrieNodeSearch(next_child, target, index + 1);
		}
	}

	TrieNode* TrieSearch(string target) {
		return TrieNodeSearch(root, target, 0);
	}

	void InsertTrieNode(TrieNode* current, string new_value, int index) {
		if (index == new_value.length()) {
			current->is_entry = true;
		} else {
			char next_letter = new_value[index];
			int next_index = LetterToIndex(next_letter);
			TrieNode* next_child = current->children[next_index];
			if (next_child == nullptr) {
				next_child = new TrieNode();
				current->children[next_index] = next_child;
			}

			InsertTrieNode(next_child, new_value, index + 1);
		}
	}

	void InsertTrie(string new_value) {
		InsertTrieNode(root, new_value, 0);
	}

	bool DeleteTrieNode(TrieNode* current, string target, int index) {
		if (index == target.length()) {
			if (current->is_entry) {
				current->is_entry = false;
			}
		} else {
			char next_letter = target[index];
			int next_index = LetterToIndex(next_letter);
			TrieNode* next_child = current->children[next_index];
			if (next_child != nullptr) {
				if (DeleteTrieNode(next_child, target, index + 1)) {
					delete next_child;
					current->children[next_index] = nullptr;
				}
			}
		}

		if (current->is_entry) {
			return false;
		}

		for (int i = 0; i < 26; i++) {
			if (current->children[i] != nullptr) {
				return false;
			}
		}

		return true;
	}

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