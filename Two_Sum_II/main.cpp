#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
	int low = 0, high = numbers.size() - 1;
	while(numbers[low] + numbers[high] != target){
		if(numbers[low] + numbers[high] < target){
			low++;
		}else{
			high--;
		}
	}
	//classic paradigm
	return vector<int>({low+1,high+1});
}

int main(){
	int a[] = {2,3,4};
	vector<int> numbers(a, a + 3);
	vector<int> res(2,0);
	res = twoSum(numbers, 6);
	for(int i = 0 ;i < res.size();i++){
		cout << res[i];
	}
	return 0;
}
