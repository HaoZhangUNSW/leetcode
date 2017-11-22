#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums){	
	int size = nums.size();
	int last = size - 1;
	for(int i = size - 2;i >=0;i--){
		if( i + nums[i] >= last){last = i;}
	}				
	return last <= 0;
}

int main(){
	vector<int> nums0 = {2,3,1,1,4};
	vector<int> nums1 = {3,2,1,0,4};
	cout << canJump(nums0) << endl;
	cout << canJump(nums1) << endl;
	return 0;
}
