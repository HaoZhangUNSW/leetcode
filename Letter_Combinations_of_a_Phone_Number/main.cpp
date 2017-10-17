#include <iostream>
#include <map>
#include <string>

using namespace std;
void letterCombinations0(string digits){	
	map<string, string> mapping;
	string letters[] = {"", ,"","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	for(int i = 0;i < 10;i ++){
		mapping[to_string(i)]=letters[i];
	}
	//vector<string> rst;
	for(int i = 0;i < digits.size();i++){
		
	}	
}
int main(){
	string digits = "23";
	letterCombinations(digits);
	return 0;
}
