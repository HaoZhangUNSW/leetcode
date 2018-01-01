#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getRst(vector<char>& stk){
	int idx = 0;
	int size = stk.size();
	while(idx < size && stk[idx] == '0'){idx++;}
	if(idx == size){return "0";}
	else{
		string rst = "";
		for(int i = idx;i < size;i++){
			rst += stk[i];
		}
		return rst;
	}
}

string removeKdigits(string& nums, int k){
	int oldNumsLen = nums.length();
	vector<char> stk;
	int top = 0;	
	for(int i = 0;i < oldNumsLen;i++){
		char curNum = nums[i];	
		while(top > 0 && stk[top-1] > curNum && k > 0){
			stk.pop_back();
			top--;
			k--;
		}
		stk.push_back(curNum);
		top++;
	}
	return getRst(stk);
}

int main(){
	string nums = "145637892";
	string nums1 = "10";
	int k = 2;
	cout << removeKdigits(nums1, k) << endl;
	return 0;
}
