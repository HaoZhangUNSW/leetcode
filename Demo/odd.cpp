#include <iostream>
using namespace std;
bool checkOdd(int val){
	if( val % 2 == 1){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	cout << (-1) % 2 << endl;
	int vals[4] = {1,2,-1,-4};
	for(auto val: vals){
		cout << checkOdd( val ) << endl;
	}
	return 0;
}
