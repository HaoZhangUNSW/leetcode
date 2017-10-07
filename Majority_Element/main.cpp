#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int majorityElement(vector<int>& nums){
	unordered_map<int, int> counts;
	int num = nums.size();
	int res = -999999;
	for(int i = 0;i < num;i++){
		if(++counts[nums[i]] > (num  / 2)){
			res=nums[i];
		}
	}
	return res;
}
int main(){
	int a[] = {1,2,3,3,3,4,3};
	vector<int> nums(a, a + 7);
	cout << majorityElement(nums) << endl;
	return 0;
}
