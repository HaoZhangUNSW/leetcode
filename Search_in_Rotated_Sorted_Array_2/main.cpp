#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		bool search(const vector<int>& nums, int target){
			int first = 0, last = nums.size();
			while(first != last){
				int mid = first + (last - first) / 2;
				if(nums[mid] == target){return true;}
				if(nums[first] < nums[mid]){
					if(nums[first] <= target && target <= nums[mid - 1]){last = mid;}
					else{first = mid + 1;}		
				
				}else if(nums[first] > nums[mid] ){
					if(nums[mid+1] <= target && target <= nums[last - 1]){
					first = mid +1;
					}else{
						last = mid;
					}
				}else{
					first++;
				}				
			}
			return false;		
		}
};
int main(){
	int a[] = {1,3,1,1,1};
	vector<int> nums(a, a + 5);
	Solution slu;
	int target = 2;
	cout << slu.search(nums, target) << endl;
	return 0;
}
