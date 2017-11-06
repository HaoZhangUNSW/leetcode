#include <iostream>
#include <cmath>
using namespace std;

double myPow(double x, int n){
	if (n == 0){return 1.0;}
	if (n < 0){
		if(n == INT_MIN){return 1.0 / (pow(x, INT_MAX) * x);}
		else{return 1.0 / pow(x, -n);}
	}
	// first method
	//return x * pow(x, n-1);
	
	// second method
	else{
		if (n % 2 == 0){
			double tmp = myPow(x, n >> 1);
			return tmp * tmp;
		}else{
			double tmp = myPow(x, (n-1) >> 1);
			return x * tmp * tmp;
		}
	}
}

int main(){
	double x = 2.0000;
	int n = 10;
	cout << myPow(x, n) << endl;
	int a = 4 >> 1;
	cout << a;		
	//cout << INT_MIN << "," << INT_MAX << endl;
	return 0;
}
