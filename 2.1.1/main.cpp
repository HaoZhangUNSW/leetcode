#include <iostream>
#include <vector>
using namespace std;

class Solution0{
	public:
		int remove(vector<int>& ary){
			if(ary.empty()){ return 0;}
			int idx = 0;
			for(int i = 0;i < ary.size();i++){
				if(ary[idx] != ary[i]){
					ary[++idx] = ary[i];
				}	
			}
			return idx + 1;	
		}

};
class Solution1{
	public:
		int remove(vector<int>& ary){
			return distance(ary.begin(), unique(ary.begin(), ary.end()));
		}
};
int main(){ 
	int a[] = {1,2,2,3,3,5};
	vector<int> ary(a, a + 6);
	Solution1 slu;
	cout << slu.remove(ary) << endl;
	return 0;
}
