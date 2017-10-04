#include <iostream>
#include <stack>
using namespace std;

class Solution{
	private:
		stack<char> strs;
	public:
		bool isValid(string s){
			if(s.empty()){return true;}	
			for(int i = 0;i < s.size();i++){
				strs.push(s[i]);
			}
			while(!strs.empty()){
				char s0 = strs.top();
				strs.pop();
				if(strs.size() == 0){return false;}
				char s1 = strs.top();
				if((s0 == ')' && s1 == '(') ||
						(s0 ==']' && s1 == '[')||
						(s0 == '}' && s1 == '{')){
					strs.pop();
					if(strs.size() % 2 != 0){
						return false;
					}
				}else{
					break;
				}
			}
	}
};

int main(){
	string strs[]  = {"","(","{}","(}","(]]","({}","{}[]()"};
	Solution slu;
	for(auto str: strs){
		cout << slu.isValid(str) << endl;
	}	
	return 0;
}
