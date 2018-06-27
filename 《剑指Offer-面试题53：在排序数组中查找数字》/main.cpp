#include <iostream>
using namespace std;

int findTarget(int* data, int length, int target){
	int low = 0;
	int high = length - 1;
	while(low < high){
		int mid = (low + high) / 2;
		if(data[mid] == target){return mid;}
		else if(data[mid] < target){low = mid;}
		else{high = mid;}
	}
	return 0;
}
int getNumber(int* data, int length, int target){
	if(data == nullptr || length <= 0){return 0;}	
	int targetLoc = findTarget(data, length, target);	
	int number = 1;
	for(int i = targetLoc - 1;i >= 0;i--){
		if(data[i] < target){break;}
		number++;
	}
	for(int i = targetLoc+1; i < length;i++){
		if(data[i] > target){break;}
		number++;
	}
	return number;
}

int main(){
	int data[] = {1,2,3,3,3,4,4,5};
	int target = 4;
	int length = sizeof(data)/sizeof(int);
	//cout << findTarget(data, length, target) << endl;
	cout << getNumber(data, length, target) << endl;
	return 0;
}
