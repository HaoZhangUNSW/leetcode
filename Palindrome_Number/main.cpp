#include <iostream>
#include <cmath>
using namespace std;

class Solution{
	public:
		bool isPalindrome(int x){
			long long r = 0;
			long long t = x;
			//t = t > 0 ? t : -t;
			if(t < 0){
				return false;
			}
			long long result = 0;
			// classic paradigm
			for(;t;t /=10){r = r * 10 + t % 10;}
			
			bool sign = x > 0 ? false : true;
			if((r > (pow(2,31) - 1)) || (sign && r > pow(2,31))){
				result = 0;
			}else{
				if(sign){
					result = -r;
				}else{
					result = r;
				}
			}
			if (x == result){
				return true;
			}else{
				return false;
			}
		}
};

int main(){
	Solution slu;
	cout << slu.isPalindrome(10101) << endl;

	return 0;
}
