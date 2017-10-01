#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		int search(const vector<int>& nums, int target){
			int first = 0, last = nums.size();
			while(first != last){
				int mid = first + (last - first) / 2;
				if(nums[mid] == target){return mid;}
				if(nums[first] <= nums[mid]){
					if(nums[first] <= target && target <= nums[mid - 1]){last = mid;}
					else{first = mid + 1;}		
				
				}else{
					if(nums[mid+1] <= target && target <= nums[last - 1]){
					first = mid +1;
					}else{
						last = mid;
					}
				}				
			}
			return -1;		
		}
};
int main(){
	int a[] = {4,5,6,7,0,1,2,3};
	vector<int> nums(a, a + 8);
	Solution slu;
	int target = 2;
	cout << slu.search(nums, target) << endl;
	return 0;
}
