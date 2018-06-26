#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int* arr, int low, int high){
	int data = arr[low];
	while(low < high){
		while( (low < high) && (arr[high] >= data) ){high--;}
		swap(arr[low], arr[high]);
		while( (low < high) && (arr[low] <= data) ){low++;}
		swap(arr[low], arr[high]);
	}	
	return low;	
}

void quickSorted(int* arr, int start, int end){
	if(start >= end){return;}
	int mid = partition(arr, start, end);
	cout << mid << endl;
	quickSorted(arr, start, mid - 1);
	quickSorted(arr, mid + 1, end);
}

int main(){
	int data[] = {9,8,7,6,5,4,3};
	int length = sizeof(data) / sizeof(int);
	quickSorted(data, 0, length - 1);
	for(int i = 0;i < length;i++){cout << data[i] << " ";}
	
	//int a = 3, b = 4;
	//swap(a, b);
	//cout << a << "," << b << endl;
	return 0;
}
