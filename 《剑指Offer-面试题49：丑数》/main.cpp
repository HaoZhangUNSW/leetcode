#include <iostream>
using namespace std;

bool isUgly(int data){
	while(data % 2 == 0){data /= 2;}
	while(data % 3 == 0){data /= 3;}
	while(data % 5 == 0){data /= 5;}
	return (data == 1) ? true : false;
}

int getUglyNum(int num){
	if(num <= 0){return 0;}
	int data = 0;
	int counter = 0;
	while(counter < num){
		++data;
		if(isUgly(data)){counter++;}
	}	
	return data;
}

int main(){
	int num = 10;
	cout << getUglyNum(num) << endl;
	return 0;
}
