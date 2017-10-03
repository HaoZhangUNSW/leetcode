#include <iostream>
#include <stack>
using namespace std;

class MinStack{
	private:
		stack<int> s1;
		stack<int> s2;
	public:
		MinStack(){
		
		}
		void push(int x){
			s1.push(x);
			if(s2.empty() || x <= getMin())
				s2.push(x);
		}
		void pop(){
			if(s1.top() == getMin())
				s2.pop();
			s1.pop();
		}
		int top(){
			return s1.top();
		}
		int getMin(){
			return s2.top();
		}
};

int main(){
	MinStack obj;
	int x0 = -3, x1 = 0, x2 = -2;
	obj.push(x0);
	obj.push(x1);
	obj.push(x2);

	obj.pop();
	int param_3 = obj.top();
	int param_4 = obj.getMin();
	cout << param_3 << "," << param_4 << endl;
	return 0;
}
