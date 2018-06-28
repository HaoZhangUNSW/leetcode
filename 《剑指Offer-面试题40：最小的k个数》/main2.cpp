#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator iterSet;	

void GetLeastNumbers(vector<int>& data, intSet& result, int k){
	result.clear();
	if(k < 1 || data.size() == 0){return;}
	vector<int>::iterator iter = data.begin();
	for(;iter != data.end();iter++){
		if(result.size() < k){
			result.insert(*iter);
		}else{
			iterSet iter_ = result.begin();
			if(*iter < *iter_){
				result.erase(iter_);
				result.insert(*iter);
			}		
		}
	}

}

int main(){
	vector<int> intVec;
	intSet result;
	intVec.push_back(5);	
	intVec.push_back(0);	
	intVec.push_back(4);	
	intVec.push_back(9);	
	intVec.push_back(2);	
	int k = 4;
	GetLeastNumbers(intVec, result, k);
	iterSet iter_ = result.begin();
	for(;iter_ != result.end();iter_++){
		cout << *iter_ << " ";
	}
	return 0;
}
