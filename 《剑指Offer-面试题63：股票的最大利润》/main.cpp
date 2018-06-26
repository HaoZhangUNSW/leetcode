#include <iostream>
using namespace std;

int getMaxGain(int* stock, int length){
	if(stock == nullptr || length < 2){return 0;}
	
	int min = stock[0];
	int maxGain = stock[1] - min;
	
	for(int i = 2;i < length;i++){
		min = stock[i-1] < min ? stock[i-1] : min;
		maxGain = stock[i] - min > maxGain ? stock[i]-min : maxGain;
	}
	
	return maxGain;
}

int main(){
	int stock[] = {9,11,8,5,7,12,16,14};
	int length  = sizeof(stock) / sizeof(int);
	cout << getMaxGain(stock, length) << endl;
	return 0;
}
