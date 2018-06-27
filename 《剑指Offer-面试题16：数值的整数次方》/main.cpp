#include <iostream>
using namespace std;

double Power(double base, unsigned int exponent){
	if(exponent == 0){return 1;}
	if(exponent == 1){return base;}

	double result = Power(base, exponent >> 1);
	result *= result;
	if(exponent & 1 == 1){result *= base;}
	return result;
}	


int main(){
	cout << Power(2.0, 5) << endl;
	return 0;
}
