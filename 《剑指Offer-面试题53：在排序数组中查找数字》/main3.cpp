#include <iostream>
using namespace std;

int getLoc(int* data, int length){
	if(data == nullptr || length <= 0){return -1;}
	int left = 0;
	int right = length - 1;
	while(left <= right){
		int mid = (left + right) >> 1;
		if(data[mid] == mid){return mid;}
		else if(data[mid] > mid){right = mid - 1;}
		else{left = mid + 1;}
	}
	return -1;
}

int main(){
	int data[] = {0,1,2,5,6};
	int length = sizeof(data) / sizeof(int);
	cout << getLoc(data, length) << endl;
	return 0;
}
