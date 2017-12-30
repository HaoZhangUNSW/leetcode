#include <iostream>
#include <vector>
#include <string>
using namespace std;

//判断给定字符串是否是回文字符串
bool isPalindrome(string words){
	if(words == "") return true;//字符串为空
	bool flag = true;
	int len = words.length();	
	for(int i = 0;i < len/2;i++){//O(lgN):包含了只有一个字符
		if(words[i] != words[len-1-i]){
			flag = false;
			return flag;
		}
	}
	return flag;
}

//找出回文对
vector<vector<int> > palindromePairs(vector<string>& words){
	int len = words.size();
	vector<vector<int> > rst;
	for(int i = 0;i < len;i++){
		for(int j = 0; j < len;j++){
			if(i != j){//(i,j)和(j,i)是不同的，i,j是字符串的索引，不是字符索引
				vector<int> TmpRst;
				string tmp = words[i]+words[j];
				if(isPalindrome(tmp)){
					TmpRst.push_back(i);
					TmpRst.push_back(j);
					rst.push_back(TmpRst);
				}
			}
		}
	}	
	return rst;
}

int main(){
	
	//TEST: is Palindrome Pairs
	//string words = "ab";
	//cout << isPalindrome(words) << endl;
	
	//TEST: palindromePairs
	vector<vector<int> > rst;
	vector<string> words = {"bat", "tab", "cat"};
	//vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
	rst = palindromePairs(words);
	
	for(auto vec:rst){
		for(auto elem: vec){
			cout << elem << endl;
		}
	}
	return 0;
}
