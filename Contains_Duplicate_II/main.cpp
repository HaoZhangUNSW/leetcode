#include <iostream>
#include <vector>
#include <set>
using namespace std;

//Can't find distinct elements
bool func(vector<int>& nums, int k){
	for(int i = 0;i < nums.size();i++){
		for(int j = 0;j < k;j++){
			if((i + j) < nums.size()){
				if(nums[i] == nums[i+j+1]){
					return true;
				}
			}
		}
	}
	return false;
}

bool _func(vector<int>& nums, int k){
	set<int> _s;
	for(int i = 0;i < nums.size();i++){
		if(i > k){_s.erase( nums[i-k-1] );}
		if(!_s.insert(nums[i]).second){return true;}
	}
	return false;
}

int main(){
	int a[] = {1,2,2,3,1,2,1,2};
	vector<int>b(a, a + 6);
	cout << _func(b, 2);
	return 0;
}
