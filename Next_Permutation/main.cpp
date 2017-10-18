#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums){
	next_permutation(nums.begin(), nums.end());	
}

int main(){
	int data[] = {1,1,5};
	vector<int> _data(data, data + sizeof(data) / sizeof(data[0]));
	nextPermutation(_data);
	for(auto& elem: _data){cout << elem << " ";}
	return 0;
}
