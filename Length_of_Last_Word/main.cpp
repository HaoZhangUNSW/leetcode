#include <iostream>
#include <string>
using namespace std;
class Solution{
	public:
		int lengthOfLastWord0(string s){
			int length = 0;
			for(int i = s.size() - 1;i >=0;i--){
				if(s[i] == ' '){
					length++;
					break;	
				}
				if(s[i] != ' '){
					length++;
				}else{
					break;
				}
			}
			return length;
		}
		int lengthOfLastWord(string s){
			int len = 0, tail = s.length() - 1;
			//过滤空格
			while(tail >= 0 && s[tail] == ' ') tail--;
			while(tail >= 0 && s[tail] != ' '){
				len++;
				tail--;
			}			
			return len;
		}
};
int main(){
	Solution slu;
	string s = " ";
	cout << slu.lengthOfLastWord(s) << endl;
	return 0;
}
