#include <iostream>
#include <vector>
#include <set>
//#include <multiset>

using namespace std;
class Solution{
	public:
		int singleNumber0(vector<int>& nums){
			set<int> snums0;
			multiset<int> snums1;
			for(int i = 0;i < nums.size();i++){
				snums0.insert(nums[i]);
				snums1.insert(nums[i]);
			}
			vector<int> setDiff;
			vector<int>:: iterator iter;
			iter = set_difference(snums1.begin(),snums1.end(),snums0.begin(),snums0.end(),setDiff.begin());
			setDiff.resize(iter-setDiff.begin());			
			for(iter = setDiff.begin();iter != setDiff.end();iter++){
				cout << *iter << endl;
			}


			//vector<int> tmp;
			//for(set<int>::iterator it = snums.begin(); it != snums.end();it++){
			//	tmp.push_back(*it);
			//}
			//for(int i = 0;i < tmp.size();i++){
			//	//remove(nums.begin(), nums.end(),tmp[i]);
			//	cout << tmp[i] << " ";
			//	nums.erase(remove(nums.begin(),nums.end(),tmp[i]), nums.end());
			//}
			return 0;
		}
		int singleNumber(vector<int>& nums){
			for(int i = 1;i < nums.size();i++){
				cout << "Before:" << nums[0] << "," << nums[i] << endl;
				nums[0] ^= nums[i];
				cout << "After:" << nums[0] << endl;
			}
			return nums[0];
		}
};

int main(){
	int a[] = {1,1,3,2,4,4,2};
	vector<int> nums(a,a + 7);
	Solution slu;
	cout << slu.singleNumber(nums) << endl;
	return 0;
}
