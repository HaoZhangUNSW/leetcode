#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int f0(vector<int>& nums, int idx){
	if(idx > nums.size()){return 0;}
	return max( nums[idx]+f0(nums, idx + 2), f0( nums, idx + 1));	
}

int f1(vector<int>& nums, int idx){
	if(idx < 0){return 0;}
	return max(nums[idx] + f1(nums, idx-2), f1(nums, idx-1));
}
int rob0(vector<int>& nums){
	//return f0(nums, 0);
	return f1(nums, nums.size() - 1);
}

int f3(vector<int>& nums, int idx, vector<int>& rst){
	if(idx < 0){return 0;}
	if(rst[idx] >= 0 ){return rst[idx];}
	rst[idx] = max(nums[idx]+f3(nums, idx - 2, rst), f3(nums, idx - 1, rst));
	return rst[idx];
}

int rob1(vector<int>& nums){
	int size = nums.size();
	vector<int> rst(size, -1);
	return f3(nums, size - 1, rst);
}

int rob2(vector<int>& nums){
	int size = nums.size();
	vector<int> rst(size, 0);
	rst[0] = nums[0];
	rst[1] = max(nums[0], nums[1]);
	for(int i = 2;i < size;i++){
		rst[i] = max(nums[i]+rst[i-2], rst[i-1]);
	}
	return rst[size-1];
}

int main(){
	int a[] = {2, 4, 8, 1, 6, 7};
	vector<int> data(a, a + sizeof(a)/sizeof(a[0]));	
	cout << rob0(data) << endl;
	return 0;
}
