#include <iostream>
#include <vector>

using namespace std;
class Solution{
	public:
		int removeElement(vector<int>& nums, int val){
			vector<int>::iterator iter;
			for(iter = nums.begin();iter != nums.end();){
				if(*iter == val){
					iter = nums.erase(iter);
				}else{
					iter++;
				}
			}
			return nums.size();	
		}
};
int main(){
	int a[] = {1,3,2,2,4,3};
	vector<int> nums(a, a + 6);
	Solution slu;
	cout <<  slu.removeElement(nums, 3) << endl;
	return 0;
}
