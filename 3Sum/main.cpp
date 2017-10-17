#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector< vector<int>> Sum_(vector<int>& numbers, int target){
	vector<int> cellar;
	vector< vector<int>> result;
	for(int i = 0;i < numbers.size();i++){
		int numberToFind = target - numbers[i];
		vector<int> _result;
		if(find(cellar.begin(), cellar.end(), numberToFind)!= cellar.end()){
			//保证返回结果中元素的顺序
			_result.push_back(numberToFind);
			_result.push_back(numbers[i]);
			//return result;	
			result.push_back(_result);
		}
		cellar.push_back(numbers[i]);
	}
	return result;
};
vector<vector<int>> duplicate(vector<vector<int>>& result){
	set<vector<int>> _result;
	for(auto& vec: result){
		sort(vec.begin(), vec.end());
		_result.insert(vec);
	}
	vector<vector<int>> res(_result.begin(), _result.end());
	return res;

}
vector< vector<int>> threeSum(vector<int>& nums){
	vector<vector<int>> result;
	for(int i = 0;i < nums.size();i++){
		vector<vector<int>> tmpResult;
		vector<int> _nums(nums);
		vector<int>::iterator it=_nums.begin()+i;
		_nums.erase(it);
		tmpResult = Sum_(_nums,-nums[i]);
		if(tmpResult.size() != 0){
			for(int j = 0;j < tmpResult.size();j++){
				tmpResult[j].push_back(nums[i]);
				result.push_back(tmpResult[j]);
			}
		}
	}
	vector<vector<int>> _result = duplicate(result);
	return _result;
}


int main(){
	//int target = 0;
	//int data[] = {-1, 0, 1, 2, -2};
	//vector<int> _data(data, data + sizeof(data)/ sizeof(data[0]));
	//vector< vector<int>> rst = Sum_(_data, target);
	//for(auto& vec : rst){for(auto& elem: vec){cout << elem << " ";}cout << endl;}
	
	int data[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<int> _data(data, data + sizeof(data)/ sizeof(data[0]));
  	vector<vector<int>> result = threeSum(_data);
	for(auto& vec : result){for(auto& elem: vec){cout << elem << " ";}cout << endl;}
	return 0;
}
