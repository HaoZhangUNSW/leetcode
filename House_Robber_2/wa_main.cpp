#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int f0(vector<int>& nums, int idx, int end){
	if(idx > end){return 0;}
	return max( nums[idx]+f0(nums, idx + 2, end), f0(nums, idx + 1, end));	
}

int f1(vector<int>& nums, int idx){
	if(idx < 0){return 0;}
	return max(nums[idx] + f1(nums, idx-2), f1(nums, idx-1));
}
int rob0(vector<int>& nums){
	int size = nums.size();
	if(size == 0){return 0;}
	if(size == 1){return nums[0];}
	if(size == 2){return max(nums[0],nums[1]);}
	return max(f0(nums, 0, size-2), f0(nums, 1, size-1));
	//return f1(nums, nums.size() - 1);
}

int f3(vector<int>& nums, int idx, vector<int>& rst){
	if(idx < 0){return 0;}
	if(rst[idx] >= 0 ){return rst[idx];}
	rst[idx] = max(nums[idx]+f3(nums, idx - 2, rst), f3(nums, idx - 1, rst));
	return rst[idx];
}

int f4(vector<int>& nums, int idx, int end, vector<int>& rst){
	if(idx > end){return 0;}
	if(rst[idx] >= 0 ){return rst[idx];}
	rst[idx] = max(nums[idx]+f4(nums, idx + 2, end, rst), f4(nums, idx + 1, end, rst));
	return rst[idx];
}

int rob1(vector<int>& nums){
	int size = nums.size();
	if(size == 0){return 0;}
	if(size == 1){return nums[0];}
	if(size == 2){return max(nums[0], nums[1]);}
	vector<int> rst(size, -1);
	return max(f4(nums, 0, size-2, rst), f4(nums, 1, size-1, rst) );
}

int rob2(vector<int>& nums,int start,int end){
	for(int i = start;i < end;i++){
		rst[i] = max(nums[i]+rst[i-2], rst[i-1]);
	}
	return rst[end];
}
int _rob(vector<int>& nums){
	int size = nums.size();
	vector<int> rst(size, 0);
	if(size == 0){return 0;}
	if(size == 1){return nums[1];}
	return max(rob2(nums, 0, size-2), rob2(nums, 1, size-1));	
}

int main(){
	int a[] = {2, 1, 1, 2};
	vector<int> data(a, a + sizeof(a)/sizeof(a[0]));	
	cout << _rob(data) << endl;
	return 0;
}
