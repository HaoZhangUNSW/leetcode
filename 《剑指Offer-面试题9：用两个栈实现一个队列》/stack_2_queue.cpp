#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

template <class T>
class MyQueue{
	public:
		MyQueue();
		~MyQueue();
		void appendTail(const T& node);
		T deleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;

};

template <class T>
MyQueue<T>::MyQueue(){cout << "constructor" << endl;}

template <class T>
MyQueue<T>::~MyQueue(){cout << "unconstructor" << endl;}

template <class T>
void MyQueue<T>::appendTail(const T& node){
	stack1.push(node);
}

template <class T>
T MyQueue<T>::deleteHead(){
	//stack2 is empty
	if(stack2.size() <= 0){
		while(stack1.size() > 0){
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}	
	//stack1 is empty
	assert(stack2.size() != 0);
	//stack2 is not empty
	T head = stack2.top();
	stack2.pop();
	return head;
}

int main(){
	MyQueue<int> queue;
	queue.appendTail(4);	
	queue.appendTail(3);	
	queue.appendTail(2);	
	cout << queue.deleteHead() << endl;
	return 0;
}
