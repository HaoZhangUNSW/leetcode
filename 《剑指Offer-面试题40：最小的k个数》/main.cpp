#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;	
}

int partition(int* data, int start, int end){
	int temp = data[start];
	while(start < end){
		while(start < end && data[end] >= temp){--end;}
		swap(data[start], data[end]);
		while(start < end && data[start] < temp){++start;}
		swap(data[start], data[end]);
	}
	return start;

}
void GetLeastNumbers(int* data, int length, int* output, int k){
	if(data == nullptr || length <= 0 || k < 0){return;}
	int start = 0;
	int end = length - 1;
	int index = partition(data, start, end);
	while(index != k-1){
		if(index > ( k - 1) ){
			end = index - 1;
			index = partition(data, start, end);
		}else{
		
			start = index + 1;
			index = partition(data, start, end);
		}
	}
	for(int i = 0;i < k;i++){output[i] = data[i];}
}

int main(){
	int data[] = {4,5,1,6,2,2,3,8};
	const int k = 4;
	int length = sizeof(data) / sizeof(int);
	int* output = new int[k];
	GetLeastNumbers(data, length, output, k);
	for(int i = 0;i < k;i++){cout << output[i] << " ";}
	return 0;
}
