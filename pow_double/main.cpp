#include <iostream>
#include <cmath>
using namespace std;

double myPow(double x, int n){
	if (n == 0){return 1.0;}
	if (n < 0){
		if(n == INT_MIN){return 1.0 / (pow(x, INT_MAX) * x);}
		else{return 1.0 / pow(x, -n);}
	}
	return x * pow(x, n-1);
}

int main(){
	double x = 2.0000;
	int n = 10;
	cout << myPow(x, n) << endl;
	//cout << INT_MIN << "," << INT_MAX << endl;
	return 0;
}
