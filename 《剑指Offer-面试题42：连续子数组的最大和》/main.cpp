#include <iostream>
using namespace std;

bool g_Invalid = false;

int getMaxSum(int* data, int length){
	if(data == nullptr || length <= 0){g_Invalid = true; return 0;}
	int maxSum = 0x80000000;
	int curSum = 0;
	for(int i = 0;i < length;i++){
		if(i == 0 || curSum <= 0){curSum = data[i];}
		else{curSum += data[i];}
		//boundary condition(>0)
		if(curSum > maxSum){maxSum = curSum;}
	}
	return maxSum;

}

int main(){
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int length = sizeof(data) / sizeof(int);
	cout << getMaxSum(data, length) << endl;
	return 0;
}
