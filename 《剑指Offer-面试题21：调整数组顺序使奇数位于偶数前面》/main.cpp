#include <iostream>
using namespace std;

bool isEven(int n){return (n & 1) == 0;}

void reorder(int* data, int length, bool (*func)(int)){
	if(data == nullptr){return;}
	int* pBegin = data;
	int* pEnd = data + length - 1;
	while(pBegin < pEnd){
		while( (pBegin < pEnd) && (!func(*pBegin)) ){pBegin++;}
		while( (pBegin < pEnd) && (func(*pEnd)) ){pEnd--;}
		if(pBegin < pEnd){
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}

}

void shuffle(int* data, int length){
	reorder(data, length, isEven);
}

int main(){
	int data[] = {4,3,2,8,5,0,9};//{3,5,9,4,2,8,0}
	int length = sizeof(data) / sizeof(int);
	shuffle(data, length);
	for(int i = 0;i < length;i++){cout << data[i] << " ";}
	return 0;
}
