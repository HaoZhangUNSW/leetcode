#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
int main(){
	//unordered_map<int, string> map;
	//map<string, string> _map;
	//_map.insert(make_pair("B","Scala"));
	//_map.insert(make_pair("C","Haskell"));
	//_map.insert(make_pair("A","C++"));
	//for(auto elem:_map){
	//	cout << elem.first << "," << elem.second << endl;
	//}
	//unordered_map<int, string>::iterator it;
	//map<string, string>::iterator it;
	//for(it = _map.begin(); it != _map.end(); it++){
	//	cout << it->first << "," << it->second << endl;
	//}
	//set<string> _set;
	unordered_multiset<string> _set;
	_set.insert("Scala");
	_set.insert("Haskell");
	_set.insert("C++");
	_set.insert("Java");
	_set.insert("Erlang");
	_set.insert("Erlang");
	unordered_multiset<string>::iterator it;
	for(it = _set.begin(); it != _set.end();it++){
		cout << *it << endl;
	}
	return 0;
}
