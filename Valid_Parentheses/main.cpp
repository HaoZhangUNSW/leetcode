#include <iostream>
#include <stack>
using namespace std;

class Solution{
	public:
		bool isValid(string s){
			stack<char> paren;
			for(auto& c : s){
				switch(c){
					case '(':
					case '{':
					case '[':paren.push(c);break;
					
					case ')':if(paren.empty() || paren.top() != '(') return false; else paren.pop();break;
					case '}':if(paren.empty() || paren.top() != '{') return false; else paren.pop();break;
					case ']':if(paren.empty() || paren.top() != '[') return false; else paren.pop();break;
					default:;
				}
			}
			return paren.empty();
		}
};

int main(){
	string strs[]  = {"","[","{}","(}","(]]","({}","{}[]()"};
	Solution slu;
	for(auto& str: strs){
		cout << slu.isValid(str) << endl;
	}	
	return 0;
}
