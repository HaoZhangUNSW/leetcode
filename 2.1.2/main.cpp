#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int remove(vector<int>& ary){
			//if(ary.empty()){return 0;}
			if(ary.size() <= 2){return ary.size();}
			int index = 2;
			for(int i = 2;i < ary.size();i++){
				// classic paradigm
				if(ary[i] != ary[index - 2]){
					ary[index++] = ary[i];
				}
				//counter++;
				//if(counter < 3){
				//	ary[++idx] = ary[i];
				//}
				//if(ary[i] != ary[idx]){
				//	if(counter > 3){
				//	}
				//}	
			}
			return index;
		}
};
int main(){
	int a[6] = {1,1,1,2,2,3};
	vector<int> ary(a, a + 6);
	Solution slu;
	cout << slu.remove(ary);
	return 0;
}
