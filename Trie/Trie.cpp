#include <iostream>
using namespace std;
int LetterToIndex(char letter) {
	return letter - 'a';
}
//트라이 구조의 노드
class TrieNode {						
public:
	bool is_entry;						//단어 판별
	TrieNode* children[26];				//자식노드들

	TrieNode() {
		is_entry = false;				//기본적으로 거짓 값을 가지게 초기화
		for (int i = 0; i < 26; i++) {	//자식 값들은 모두 비어있게 설정
			children[i] = nullptr;
		}
	}
};
//트라이의 구조
class Trie {					
public:
	TrieNode* root;				//근본노드

	Trie() {
		root = new TrieNode();	//근본이 비어있을 시 작동이 되지 않으므로 트라이 구조 생성시 근본도 같이 생성
	}
	//탐색메서드(상세)
	TrieNode* TrieNodeSearch(TrieNode* current, string target, int index) {	
		if (index == target.length()) {		//탐색 단어의 길이와 현재의 인덱스가 같을때
			if (current->is_entry) {		//그 글자의 단어 여부가 참이라면
				return current;				//현재 노드 반환
			} else {						//단어 여부가 거짓이라면
				return nullptr;				//빈 포인터 반환
			}
		}//단어의 길이보다 인덱스 값이 적을 때 
		char next_letter = target[index];	
		int next_index = LetterToIndex(next_letter);
		TrieNode* next_child = current->children[next_index];	
		if (next_child == nullptr) {		//자식이 비어있다면 빈 포인터 반환
			return nullptr;
		} else {							//비어있지 않다면 다음 인덱스로 계속 탐색
			return TrieNodeSearch(next_child, target, index + 1);	
		}
	}
	//탐색 메서드
	TrieNode* TrieSearch(string target) {
		return TrieNodeSearch(root, target, 0);
	}
	//삽입 메서드(상세)
	void InsertTrieNode(TrieNode* current, string new_value, int index) {
		if (index == new_value.length()) {						//추가글자와 인덱스 값이 같을때
			current->is_entry = true;							//해당 노드의 글자 여부를 참으로 바꾼다
		} else {												//인덱스 값이 더 적을때
			char next_letter = new_value[index];
			int next_index = LetterToIndex(next_letter);
			TrieNode* next_child = current->children[next_index];
			if (next_child == nullptr) {						//자식이 비어있다면
				next_child = new TrieNode();					//새로운 노드 할당
				current->children[next_index] = next_child;		//자식에 새로운 노드 삽입
			}

			InsertTrieNode(next_child, new_value, index + 1);	//자식으로 이동해서 다시 실행
		}
	}
	//삽입 메서드
	void InsertTrie(string new_value) {
		InsertTrieNode(root, new_value, 0);
	}
	//삭제 메서드(상세)
	bool DeleteTrieNode(TrieNode* current, string target, int index) {
		if (index == target.length()) {									//삭제 단어의 길이와 인덱스가 같을 때
			if (current->is_entry) {									//현재 노드의 단어 여부가 참이라면
				current->is_entry = false;								//거짓으로 바꿈
			}
		} else {														//인덱스 값이 단어의 길이보다 적을 때
			char next_letter = target[index];
			int next_index = LetterToIndex(next_letter);
			TrieNode* next_child = current->children[next_index];
			if (next_child != nullptr) {								//자식이 비어있지 않다면
				if (DeleteTrieNode(next_child, target, index + 1)) {	//자식이 지워도 되는 노드라면
					delete next_child;
					current->children[next_index] = nullptr;			//자식을 비움
				}
			}
		}

		if (current->is_entry) {										//현재 노드의 단어 여부가 참이라면
			return false;												//비워도 되는 노드가 아니라고 알림
		}

		for (int i = 0; i < 26; i++) {									
			if (current->children[i] != nullptr) {						//자식 중 하나라도 비어있지 않은 자식이 있다면
				return false;											//비워도 되는 노드가 아니라고 알림
			}
		}

		return true;													//이 모든 과정에서 걸러지지 않았다면 
	}																	//비워도 되는 노드라고 알림
	//삭제 메서드
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