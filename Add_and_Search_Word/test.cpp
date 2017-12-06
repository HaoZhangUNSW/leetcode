#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
	set<string> _set;
	_set.insert("bi");
	_set.insert("dad");
	_set.insert("done");
	_set.insert("dog");
	for(auto elem: _set){cout << elem << endl;}
	return 0;
}
