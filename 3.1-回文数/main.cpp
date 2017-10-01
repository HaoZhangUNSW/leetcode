#include <iostream>
#include <string>
using namespace std;

class Solution{
	public:
		bool isPalindrome(string s){
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			auto left = s.begin(), right = prev(s.end());
			while(left < right){
				if(! ::isalnum(*left)){++left;}
				else if(! ::isalnum(*right)){++right;}
				else if(*left != *right){return false;}
				else{left++,right--;}
			}			
			return true;
		}
};
int main(){
	string s = "AmanaplanacanalPanama";
	Solution slu;
	cout << slu.isPalindrome(s) << endl;
	//string str = "zhpmatrix";
	//string str1 = "";
	//auto left = str1.begin(), right = prev(str1.end());
	//if(left > right){
	//	cout << "True" << endl;
	//}
	//cout << left << endl;
	//cout << *(str.begin()) << "," << *(str.end()) << endl;
	//cout << *str.end() << endl;
	//cout << *prev(str.end()) << endl;
	return 0;
}
