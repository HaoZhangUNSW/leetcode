#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target){
 	int low = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
	int high = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
	if(nums[low] != target){
		return vector<int>{-1,-1};
	}
	else{
		return vector<int>{low, high};
	}
}
int  main(){
	vector<int> data={5,8,7,7,8,10};
	vector<int> rst = searchRange(data, 8);
	for(auto& elem: rst){cout << elem << " ";}
	return 0;
}
