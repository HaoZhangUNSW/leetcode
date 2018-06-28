#include <iostream>
using namespace std;

int numberOf1(int n){
	int number = 0;
	while(n){
		if(n % 10 == 1){number++;}
		n /= 10;	
	}
	return number;
}

int getTotal(int n){
	int number = 0;
	for(int i = 1;i <= n;i++){
		number += numberOf1(i);
	}
	return number;
}


int main(){
	cout << getTotal(12) << endl;
	return 0;
}
