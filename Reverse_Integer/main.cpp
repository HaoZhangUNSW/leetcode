#include <iostream>
#include <cmath>
using namespace std;

class Solution{
	public:
		int reverse(int x){
			long long r = 0;
			long long t = x;
			t = t > 0 ? t : -t;
			
			// classic paradigm
			for(;t;t /=10){r = r * 10 + t % 10;}
			
			bool sign = x > 0 ? false : true;
			if((r > (pow(2,31) - 1)) || (sign && r > pow(2,31))){
				return 0;
			}else{
				if(sign){
					return -r;
				}else{
					return r;
				}
			}
		
		}
};

int main(){
	Solution slu;
	cout << slu.reverse(123) << endl;
	cout << pow(2,31) << endl;
	return 0;
}
