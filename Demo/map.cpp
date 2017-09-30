#include <iostream>
#include <map>
using namespace std;
int main(){
	map<int, int> _map;
	_map[0] = 2;
	_map[1] = 3;
	_map[1]++;
	cout << _map[1];
	return 0;
}
