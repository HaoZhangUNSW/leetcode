#include <iostream>
using namespace std;

class Solution{
	public:
	
		int climbStairs0(int n){
			int a = 1,b = 1;
			while(n--){
				a = (b += a) -a;
			}
			return a;
		}
		int climbStairs(int n){
			if(n == 0 || n == 1 || n == 2){return n;}
			
			int* mem = new int[n];
			
			int steps = 0;
			mem[0] = 1;
			mem[1] = 2;
			for(int i = 2;i < n;i++){
				mem[i] = mem[i-1] + mem[i-2];
			}
			steps = mem[n-1];

			//子函数中的资源要释放
			delete[] mem;
			
			return steps;
		}
};

int main(){
	Solution slu;
	cout << slu.climbStairs(6) << endl;
	return 0;
}
