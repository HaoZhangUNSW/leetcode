#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
	public:
    		bool end;
    		TrieNode* next[26];
    		TrieNode() {
        		memset(next, 0, sizeof(next));
        		end = false;
    		}
};

class WordDictionary {
	public:
    		// 字典树的根节点
    		TrieNode* trie_root;
	       	WordDictionary() {
        		trie_root = NULL;
    		}
    		
		// 回溯法查找单词word是否存在
    		bool dfs(TrieNode* node, string& word, int id) {
        		if (id == word.length()) {
            			if (true == node->end) {
                			return true;
            			}else{
                			return false;
            			}
        		}
			if ('.' == word[id]) {
			    for (int i = 0; i < 26; ++i) {
				if (node->next[i] && dfs(node->next[i], word, id + 1)) {
				    return true;
				}
			    }
			    return false;
			} else {
			    if (NULL == node->next[word[id] - 'a']) {
				return false;
			    } else {
				return dfs(node->next[word[id] - 'a'], word, id + 1);
			    }
			}
		    }
   
		    // Adds a word into the data structure.
		    void addWord(string word) {
			if (trie_root == NULL) {
			    trie_root = new TrieNode();
			}
			TrieNode* tmp = trie_root;
			for (int i = 0; i < word.length(); ++i) {
			    if (tmp->next[word[i] - 'a'] == NULL) {
				tmp->next[word[i] - 'a'] = new TrieNode();
			    }
			    if (i < word.length() - 1) {
				tmp = tmp->next[word[i] - 'a'];
			    } else {
				tmp->next[word[i] - 'a']->end = true;
			    }
			}
		    }
		    // Returns if the word is in the data structure. A word could
		    // contain the dot character '.' to represent any one letter.
		    bool search(string word) {
			if (trie_root == NULL) {
			    trie_root = new TrieNode();
			}
			
			return dfs(trie_root, word, 0);
		    }
};

int main(){
	WordDictionary obj;
	vector<string> words={"bad","dad","mad"};
	for(auto word:	words){obj.addWord(word);}
	vector<string> rgxs = {"cad","pad","mad","b.m"};
	for(auto rgx:	rgxs){
		cout << "-----------------------" << endl;
		cout << obj.search(rgx) << endl;
		cout << "-----------------------" << endl;
	}
	return 0;
}
