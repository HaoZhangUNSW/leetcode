#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
	list<int> nums = {0,1,2,3,4};
	list<int>::iterator iter = nums.begin();
	//cout << * iter << endl;
	//for(;iter != nums.end();iter++){cout << * iter << endl;}
	
	iter = nums.erase(iter);
        
	//without return value
	//nums.erase(iter);
	cout << *iter << endl;
	return 0;
}
