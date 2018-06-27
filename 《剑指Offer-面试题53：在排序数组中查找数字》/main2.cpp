#include <iostream>
using namespace std;

int getMissingNumber(int* data, int length){
	int target = 0;
	int real = 0;
	for(int i = 0;i < length;i++){
		target += i;
		real += data[i];
	}
	return target - real + length;
}
int getMissingNumber_(int* data, int length){
	//return value = -1;
	if(data == nullptr || length <= 0){return -1;}
	int left = 0;
	int right = length - 1;
	while(left < right){
		int mid = (left + right) >> 1;
		if(data[mid] != mid){
			if(mid == 0 || (data[mid - 1] == (mid - 1))){
				return mid;
			}
			right = mid;
		}else{
			left =  mid;
		}
	}
	if(left == length){return length;}
	return -1;//invalid input
}

int main(){
	int data[] = {0,1,3,4,5,6};
	int length = sizeof(data)/ sizeof(int);
	cout << getMissingNumber_(data, length) << endl;
	return 0;
}
