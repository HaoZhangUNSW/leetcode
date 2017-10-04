#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
		//时间复杂度为O(n)的解法
		int maxSubArray0(vector<int>& nums){
			int ans = nums[0],sum=0;
			for(int i = 0;i < nums.size();i++){
				sum += nums[i];
				//子数组最值
				ans = max(sum, ans);
				//sum<0时,清零
				sum = max(sum, 0);
			}
			return ans;
		}
		//动态规划解法: 我喜欢!
		int maxSubArray1(vector<int>& nums){
			int length = nums.size();

			//dp[i]表示最大子数组以nums[i]为结尾元素
			int* dp = new int[length];
			dp[0] = nums[0];
			int _max = dp[0];
			for(int i = 1;i < length;i++){
				dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1]:0);
				_max = max(_max, dp[i]);
			}
			delete[] dp;
			return _max;
			
		}
};

int main(){
	int ary[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(ary, ary+9);
	Solution slu;
	cout << slu.maxSubArray1(nums) << endl;
	return 0;
}
