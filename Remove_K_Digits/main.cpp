#include <iostream>
#include <string>
#include <vector>
using namespace std;

string removeKdigits(string& nums, int k){
	int oldNumsLen = nums.length();
	int newNumsLen = oldNumsLen - k;
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
	int idx = 0;
	while(idx < newNumsLen && stk[idx] == '0'){idx++;}
	if(idx == newNumsLen){return "0";}
	else{
		string rst = "";
		for(int i = idx;i < newNumsLen;i++){
			rst += stk[i];
		}
		return rst;
	}
}

int main(){
	string nums = "10";
	int k = 2;
	cout << removeKdigits(nums, k) << endl;
	return 0;
}
