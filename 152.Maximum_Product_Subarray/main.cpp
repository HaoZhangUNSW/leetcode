int maxProduct(vector<int>& nums){
	int res = nums[0], n = nums.size();
	vector<int> maxProduct(n, 0), minProduct(n,0);
	maxProduct[0] = nums[0];
	minProduct[0] = nums[0];
	for(int i = 1;i < n;i++){
		maxProduct[i] = max( max( maxProduct[i-1] * nums[i] , minProduct[i-1] * nums[i] ), nums[i] );
		minProduct[i] = min( min( maxProduct[i-1] * nums[i] , minProduct[i-1] * nums[i] ), nums[i] );
		res = max(res, maxProduct[i]);
	}
	return res;
}
