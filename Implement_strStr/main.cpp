#include <iostream>
#include <string>

using namespace std;
class Solution{
	public:
		int strStr(string haystack, string needle){
			if(needle == " "){return 0;}
			int window = needle.size();
			for(int i = 0;i < haystack.size();i++){
				string tstr = haystack.substr(i,window);
				if(tstr ==  needle){
					return i;
				}
			}
			return -1;
		}
};
int main(){
	string haystack  = "12345";
	string needle = "3";
	Solution slu;
	cout << slu.strStr(haystack, needle) << endl;
	return 0;
}
