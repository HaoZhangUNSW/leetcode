#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int robber(vector<int>& nums, int l, int h){
	int pre = 0, cur = 0;
	for(int i = l;i <= h;i++){
		int tmp = max(pre + nums[i], cur);
		pre = cur;
		cur = tmp;
	}
	return cur;
}
int rob(vector<int>& nums){
	int size = nums.size();
	if(size < 2){return size ? nums[0] : 0;}
	return max(robber(nums, 0, size - 2), robber(nums, 1, size - 1));
}

int main(){
	int a[] = {2, 1, 1, 2};
	vector<int> data(a, a + sizeof(a)/sizeof(a[0]));	
	cout << rob(data) << endl;
	return 0;
}
