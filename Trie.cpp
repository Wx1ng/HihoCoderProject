#include <iostream>
#include <cstring>
using namespace std;

class trieNode{
public:
	int n;	//记录以此节点为前缀的单词个数
	char ch;
	trieNode *child[26];
	//构造函数
	trieNode(){
		n = 0;
		ch = 0;
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
	}
	//析构函数
	/*~trieNode(){
		if (child != NULL)
			delete []child;
	}*/
};

class trie{
public:
	trieNode root;
	void insert(trieNode* tn, const char* str);
	int search(trieNode* tn, const char* str);
};

void trie::insert(trieNode* tn, const char* str){
	trieNode** pTn = tn->child;
	for (int i = 0; i < strlen(str); i++){	
		bool isVisited = false;
		while (pTn[0] != NULL){
			if (pTn[0]->ch == str[i]){
				pTn[0]->n++;
				pTn = pTn[0]->child;
				isVisited = true;
				break;
			}
			else
				pTn++;		
		}
		if (pTn[0] == NULL && !isVisited){
			pTn[0] = new trieNode();
			pTn[0]->ch = str[i];
			pTn[0]->n += 1;
			pTn = pTn[0]->child;
			continue;
		}
	}
}

int trie::search(trieNode* tn, const char* str){
	int Ans = 0;
	trieNode** pTn = tn->child;
	for (int i = 0; i < strlen(str); i++){
		if (pTn[0] == NULL)
			return 0;
		while (pTn[0] != NULL){
			if (pTn[0]->ch == str[i]){
				Ans = pTn[0]->n;
				pTn = pTn[0]->child;
				break;
			}
			else{
				pTn++;
				if (pTn[0] == NULL)
					return 0;
			}
		}
	}
	return Ans;
}

int main(){
	trie wordDict;
	//插入
	int dictSize;
	cin >> dictSize;
	cin.get();
	while (dictSize--){
		char newWord[10];
		cin.getline(newWord, 11);
		wordDict.insert(&wordDict.root, newWord);
	}
	//查询
	int querySize;
	cin >> querySize;
	cin.get();
	while (querySize--){
		char queryWord[10];
		cin.getline(queryWord, 11);
		cout << wordDict.search(&wordDict.root, queryWord) << endl;
	}
	return 0;
}
