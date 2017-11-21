#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	vector<int>rst;
	for(int i = 0;i < nums.size();i++){
		int obj = target - nums[i];
		for(int j = i + 1;j < nums.size();j++){
			if(nums[j] == obj){
				rst.push_back(i);
				rst.push_back(j);
				return rst;
			}
		}
	}
	return rst;
}

vector<vector<int> > threeSum(vector<int>& nums){
	vector<vector<int> >rst;
	sort(nums.begin(), nums.end());
	for(int i = 0;i < nums.size();i++){
		int target = -nums[i];
		int front = i + 1;
		int back = nums.size() - 1;
		//corner case
		while(front < back){
			int sum = nums[front] + nums[back];
			if(sum < target){front++;}
			else if(sum > target){back--;}
			else{
				vector<int> tmpRst(3,0);
				tmpRst[0] = nums[i];tmpRst[1] = nums[front];tmpRst[2]=nums[back];
				rst.push_back(tmpRst);
				//idx2, idx3 duplicate
				while(front < back && nums[front] == tmpRst[1]){front++;}
				while(front < back && nums[back] == tmpRst[2]){back--;}
			}	
		}
		//idx1 duplicate	
		while(i+1 < nums.size() && nums[i+1] == nums[i]){i++;}	
	}	
	return rst;
}

int threeSumClosest(vector<int>& nums, int target){
	int size = nums.size();
	if(size < 3){return 0;}
	int closest = nums[0] + nums[1] + nums[2];
	
	sort(nums.begin(), nums.end());
	for(int first = 0;first < size - 2;first++){
		//duplicate
		if(first > 0 && nums[first] == nums[first-1]){continue;}
		int second = first + 1;
		int third = size - 1;
		while(second < third){
			int curSum = nums[first] + nums[second] + nums[third];
			if(abs(target-curSum) < abs(target-closest)){closest = curSum;}
			else if(curSum < target){second++;}
			else{third--;}

		}
	
	}
	return closest;
}

vector<vector<int> > fourSum(vector<int>& nums, int target){
	vector<vector<int> >rst;
	sort(nums.begin(), nums.end());
	int size = nums.size();
	for(int i = 0;i < size;i++){
		int t3 = target-nums[i];
		for(int j = i + 1;j < size;j++){
			int t2 = t3 - nums[j];
			int front = j + 1;
			int back = size - 1;
			while(front < back){
				int curSum = nums[front] + nums[back];
				if(curSum < t2){front++;}
				else if(curSum > t2){back--;}
				else{
					vector<int> tmpRst(4,0);
					tmpRst[0] = nums[i];
					tmpRst[1] = nums[j];
					tmpRst[2] = nums[front];
					tmpRst[3] = nums[back];
					rst.push_back(tmpRst);
					while(front < back && nums[front] == tmpRst[2]){front++;}	
					while(front < back && nums[back] == tmpRst[3]){back--;}	
				
				}
			}
			//duplicate idx2
			while(j+1 < size && nums[j+1] == nums[j]){j++;}	
		}	
	
	//duplicate idx1
	while(i+1 < size && nums[i+1] == nums[i]){i++;}	
	}
	return rst;
}

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
	unordered_map<int, int> hash;
	for(auto& a: A){
		for(auto& b: B){
			hash[a+b]++;
		}
	}
	int count = 0;
	for(auto& c:C){
		for(auto& d:D){
			auto it = hash.find(0 - c - d);
			if(it != hash.end()){count += it->second;}
		}
	}
	return count;
}

int main(){
	//int a[] = {2, 7, 11, 15};int target = 9;
	//vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
	//vector<int> rst = twoSum(nums, target);
	
	//int b[] = {1, 0, -1, 0, -2, 2};int target = 0;
	//vector<int> nums(b, b + sizeof(b)/sizeof(b[0]));
	//vector<vector<int> >rst = fourSum(nums, target);
	
	//for(auto& elem0: rst){
	//	for(auto& elem1: elem0){	
	//		cout << elem1 << endl;
	//	}
	//}

	//int c[] = {1, 1, 1, 0};int target = 1;
	//vector<int> nums(c, c + sizeof(c)/sizeof(c[0]));
	//cout << threeSumClosest(nums, target) << endl;	
	int a[] = {1,2};vector<int>_a(a, a + 2);
	int b[] = {-2,-1};vector<int>_b(b, b + 2);
	int c[] = {-1,2};vector<int>_c(c, c + 2);
	int d[] = {0,2};vector<int>_d(d, d + 2);
	cout << fourSumCount(_a, _b, _c, _d) << endl;
	return 0;
}
