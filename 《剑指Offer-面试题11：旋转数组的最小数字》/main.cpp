#include <iostream>
#include <cassert>
using namespace std;

int getMinFromArr(int* data, int num){
	//if(data == nullptr || num == 0){
	//	throw new exception("Invalid params!");
	//}
	
	assert(data != nullptr && num != 0);
	
	int first = 0;
	int second = num - 1;
	int mid  = first;
	while( data[first] >= data[second]){
		if( (second - first) == 1){mid = second;break;}
		mid = (first + second) / 2;
		if(data[mid] >= data[first]){first = mid;}
		else{second = mid;}	
	}	
	return data[mid];
}

int main(){
	int data[] = {3,4,5,1,2};
	int num = sizeof(data)/sizeof(data[0]);
	//TODO
	cout << getMinFromArr(data, num) << endl;
	return 0;
}
