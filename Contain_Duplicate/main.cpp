#include <iostream>
using namespace std;
bool containDuplicate(vector<int>& nums){
	set<int> s;
	for(int i = 0;i < nums.size();i++){s.insert(nums[i]);}
	if((nums.size() - s.size()) > 0){return true;}
	else{return false;}
}
int main(){
	return 0;
}
