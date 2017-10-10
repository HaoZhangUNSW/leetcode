#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class MyQueue{
	public:
		stack<int> s0;	//main container
		stack<int> s1;	//sub container
		MyQueue(){}
		void push(int x){
			while(!s0.empty()){
				s1.push(s0.top());
				s0.pop();
			}
			s0.push(x);
			while(!s1.empty()){
				s0.push(s1.top());
				s1.pop();
			}
		}
		int pop(){
			int res = s0.top();
			s0.pop();
			return res;
		}
		int peek(){
			return s0.top();
		}
		bool empty(){
			return s0.empty();
		}
};
int main(){
	//stack<int> s;
	//queue<int> s;
	//s.push(4);
	//s.push(5);
	//s.push(6);
	//cout << s[0] << "," << s[1];
	///////////////////////////////
	MyQueue que;
	que.push(3);
	que.push(4);
	cout << que.peek()<<"," << que.empty();
	return 0;
}
