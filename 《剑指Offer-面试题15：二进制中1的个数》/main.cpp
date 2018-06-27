#include <iostream>
using namespace std;

/***
 * 遇到负数的时候会出现死循环。因为n右移时，针对负数，高位会补1，保证为负。
 *
 *
 * ***/
int NumberOf1_(int n){
	int number = 0;
	while(n){
		if(n & 1){number++;}
		n >>= 1;
	}
	return number;
}

/***
 * 为了解决上述问题，n不懂，动flag位， flag左移。
 *
 *
 *
 * ***/
int NumberOf1(int n){
	int number = 0;
	unsigned int flag =1;
	while(flag){
		if(n & flag){number++;}
		flag <<= 1;
	}
	return number;
}
int main(){
	int n = -11;
	cout << NumberOf1(n) << endl;
	return 0;
}
