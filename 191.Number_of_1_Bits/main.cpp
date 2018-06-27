#include <iostream>
using namespace std;
int main(){
	int a = 11;
	int number = 0;
	while(a != 0){
		if( a & 1){number++;}
		a >>= 1;
	}
	cout << number << endl;
	return 0;
}
