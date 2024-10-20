#include <iostream>
using namespace std;
class TrieNode {
	bool is_entry;			//단어 판별
	TrieNode* children[26];	//자식노드들
};

class Trie {
	TrieNode* root;			//근본노드
};
int main() {

}