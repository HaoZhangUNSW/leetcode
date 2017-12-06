class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode(char input='#'):isEnd(false) {}
	bool isEnd;//需要一个end标志判断是否到达结尾
	unordered_map<char, TrieNode*> child;//将一个节点下的所有节点存在unordered_map中
};

//插入：首先把根节点当做当前节点，然后从unordered_map中查找是否这个字符，如果找到则把找到的节点当做当前节点，没找到则新建一个节点插在原节点上，然后把新建的节点当做当前节点
class Trie {
public:
	Trie() {root = new TrieNode();}
                void insert(string word) {
		TrieNode *iter=root;
		for (int i = 0; i < word.size(); i++)
		{
			if (iter->child.find(word[i]) != iter->child.end())//找到，则把找到的当做待处理节点
			{
				iter = iter->child[word[i]];
			}
			else//找不到，新建节点
			{
				TrieNode *temp = new TrieNode(word[i]);
				iter->child[word[i]] = temp;
				iter = temp;
			}
		}
		iter->isEnd = true;
}
	bool search(string word) {
		TrieNode *iter = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (iter->child.find(word[i]) != iter->child.end())//找到，则把找到的当做待处理节点
			{
				iter = iter->child[word[i]];
			}
			else//找不到，新建节点
			{
				return false;
			}
		}
		if (iter->isEnd) return true;
		return false;//只是前缀也是false
	}
	bool startsWith(string prefix) {
		TrieNode *iter = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (iter->child.find(prefix[i]) != iter->child.end())//找到，则把找到的当做待处理节点
			{
				iter = iter->child[prefix[i]];
			}
			else//找不到，新建节点
			{
				return false;
			}
		}
		return true;
	}
private:
	TrieNode* root;
};
