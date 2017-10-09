#include <iostream>
#include <vector>
using namespace std;

void disp(vector<int>& arr){
	for(const auto& val:arr){
		cout << val << " ";
	}
}

int lenOfLIS(vector<int>& arr){
	int len = arr.size();
	int f[len];
	if (len == 0){
		return 0;
	}
	for(int i = 0;i < len;i++){
		f[i] = 1;
	}
	int max = 1;
	for(int i = 0;i < len;i++){
		for(int j = 0;j < i;j++){
			if( (arr[i] > arr[j]) && (f[j] + 1 > f[i]) ){
				f[i] = f[j] + 1;
				if(f[i] > max){
					max = f[i];
				}
			}
		}
	}
	return max;
}

int main(){
	int a[] = {10,9,2,5,3,7,101,18};
	vector<int> arr(a,a+sizeof(a)/sizeof(int));
	cout << "arr:";disp(arr);
	cout << "\nlenOfLIS:" << lenOfLIS(arr) << endl;
	return 0;
}
