#include <iostream>
#include <vector>
using namespace std;

void moveZeros(vector<int>& nums){
	int j = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] != 0){nums[j++]=nums[i];}	
	}
	for(;j < nums.size();j++){nums[j]=0;}		
}

int main(){
	int a[] = {0,1,0,3,12};
	vector<int> nums(a,a + 5);
	moveZeros(nums);
	for(int i = 0;i < nums.size();i++){cout << nums[i]; }
	return 0;
}
