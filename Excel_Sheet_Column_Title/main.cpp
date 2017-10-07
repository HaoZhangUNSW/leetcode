#include <iostream>
#include <string>
using namespace std;
string convertToTitle(int n){
	return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');
}
int main(){
	cout << convertToTitle(235);
	return 0;
}
