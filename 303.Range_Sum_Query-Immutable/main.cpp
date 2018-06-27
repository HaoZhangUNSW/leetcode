#include <iostream>
#include <vector>
using namespace std;
class NumArray{
	public:
		NumArray(vector<int> nums){
			m_vNums = nums;
		}
		int sumRange(int i, int j){
			//boundary condition
			if(i < 0 || j > m_vNums.size() - 1 || i > j){return 0;}
			int sum = 0;
			for(int k = i; k <= j;k++){
				sum += m_vNums[k];
			}	
			return sum;
		}

		const int getSize() const{return m_vNums.size();}
	private:
		vector<int> m_vNums;
};
int main(){
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(-5);
	nums.push_back(2);
	nums.push_back(-1);
	NumArray* obj = new NumArray(nums);
	int first[] = {0,2,0};
	int second[] = {2,5,5};
	int length = sizeof(first) / sizeof(int);
	for(int i = 0;i < length;i++){
		int param_1 = obj->sumRange(first[i],second[i]);
		cout << param_1 << endl;
	}
	delete obj;
	return 0;
}
