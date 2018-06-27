/***
 * 和为s的连续正数序列[hard]!!!
 * LeetCode上有两个数，三个数或者更多的数的和。
 * ***/

#include <iostream>
using namespace std;

bool Find(int* data, int length, int sum, int* a, int* b){
	bool found = false;
	if(data == nullptr || length < 1 || a == nullptr || b == nullptr){return found;}
	int ahead = 0;
	int behind = length - 1;
	while(behind > ahead){
		int curSum = data[ahead] + data[behind];
		if(curSum == sum){
			*a = data[ahead];
			*b = data[behind];
			found = true;
			break;
		}else if(curSum > sum){behind--;}
		else{ahead++;}	
	}
	return found;	
}

int main(){
	int data[] = {1,2,4,7,11,15};
	int length = sizeof(data) / sizeof(int);
	int sum = 15;
	int a = 0;
	int b = 0;
	cout << Find(data, length, sum, &a, &b) << endl;
	cout << a << "," << b << endl;
	return 0;
}
