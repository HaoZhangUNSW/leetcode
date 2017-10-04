#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		int searchInsert(vector<int>& nums, int target){
			int low = 0, high = nums.size() - 1;
			while(low <= high){
				int mid = low + (high-low)/2;
				if(nums[mid] < target){
					low = mid + 1;
				}else{
					high = mid - 1;
				}
			}	
			return low;
		}
};

int main(){

	int ary[] = {1,3,5,6};
	vector<int> nums(ary, ary+4);

	Solution slu;
	cout << slu.searchInsert(nums,7) << endl;

	return 0;
}
