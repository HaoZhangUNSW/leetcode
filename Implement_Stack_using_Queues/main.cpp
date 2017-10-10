#include <iostream>
#include <queue>
using namespace std;

//class MyStack{
//	private:
//		queue<int> q0;
//		queue<int> q1;
//	public:
//		MyStack(){}
//		void push(int x){
//			if(!q1.empty()){
//				q1.pop();
//				q1.push(x);
//			}else{
//				q1.push(x);
//			}
//			q0.push(x);
//		}
//		int pop(){
//			int res = q1.front();
//			q1.pop();
//			if(!q0.empty()){
//				q1.push(q0.back());
//			}
//			return res;
//		}
//		int top(){
//			return q1.front();
//		}
//		bool empty(){
//			return q1.empty();		
//		}
//};

class MyStack{
	private:
		queue<int> q;
	public:
		void push(int x){
		q.push(x);
		for(int i = 0;i < q.size() - 1;i++){
			q.push(q.front());
			q.pop();
		}	
	}
	int  pop(){
		int res;
		res = q.front();
		q.pop();
		return res;
	}
	int top(){return q.front();}
	bool empty(){return q.empty();}
};

int main(){
	//MyStack obj = new MyStack();
	MyStack obj;
	obj.push(3);
	obj.push(4);
	int val0 = obj.pop();
	int val1 = obj.top();
	cout << val0 << "," << val1 << endl;
	cout << obj.empty();
	return 0;
}
