#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	string str;
	while(cin >> str){
		vector<string> list;
		for(int i= 0;i < str.size();i++){
			string tmp = str.substr(i);
			cout << tmp << endl;
			list.push_back(tmp);
		}
		sort(list.begin(), list.end());
		for(int i = 0;i < list.size();i++){
			cout << list[i] <<  endl;
		}
	
	
	}
	return 0;
}
