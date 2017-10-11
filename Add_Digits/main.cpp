#include <iostream>
using namespace std;

int addDigits(int num){
	while(num >= 10){
		int tmp = 0;
		while(num){
			tmp += num%10;
			num /= 10;
		}
		num = tmp;
	}	
	return num;
}

int main(){
	cout << addDigits(38);
	return 0;
}
