#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> data;
	data.push_back(10);
	data.push_back(20);
	data.push_back(30);
	data.push_back(40);
	data.push_back(50);
	vector<int>::iterator iter;
	vector<int>::iterator ptr;
	ptr = remove(data.begin(), data.end(), 10);
	ptr = remove(data.begin(), data.end(), 20);
	for(auto &elem : data){cout << elem << endl;}
	return 0;
}
