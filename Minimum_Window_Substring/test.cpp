#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str0 = "ABM";
	string str1 = "BMA";
	unordered_map<char, int> map0;
	unordered_map<char, int> map1;
	for(auto& str:str0){map0[str]++;}
	for(auto& str:str1){map1[str]++;}
	cout << (map0 == map1) << endl;
	cout << map0.size() << endl;
	return 0;
}
