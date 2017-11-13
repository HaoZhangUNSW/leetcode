#include <iostream>
using namespace std;

void hannoi(int n, char a, char b, char c){
	if(n == 1){
		cout << "move " << n << " from " << a << " to " << c << endl;
	}else{
		hannoi(n-1, a, c, b);
		cout << "move " << n << " from " << a << " to " << c << endl;
		hannoi(n-1, b, a, c);
	}
}

int main(){
	hannoi(3, 'a', 'b', 'c');
	return 0;
}
