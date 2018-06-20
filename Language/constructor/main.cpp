#include <iostream>
using namespace std;
class A{
	public:
		A(int n){value = n;}
		//A(A other){value = other.value;}
		A(const A& other){
			cout << "copy constructor" << endl;
			value = other.value;
		}
		void Print(){cout << value << endl;}
	private:
		int value;	

};
int main(){
	A a(10);
	A b = a;
	b.Print();
	return 0;
}
