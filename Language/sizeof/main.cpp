#include <iostream>
using namespace std;

class Person{};

int getArrSize(int data[]){return sizeof(data);}

int main(){
	/***
	 *
	 * case 0: naive version(res=1)
	 * case 1: class declaration with constructor and unconstructor(res=1)
	 * case 2: class declaration with virtual function(res=4 in 32bit for virtual function table)
	 *
	 * ***/
	Person p;
	cout << sizeof(p) << endl;
	
	int data0[] = {1,2,3,4};
	cout << sizeof(data0) << endl;//16

	int* data1 = data0;
	cout << sizeof(data1) << endl;//8

	//数组作为函数的参数进行传递时，数组就自动退化为同类型的指针
	int size3 = getArrSize(data0);//8	
	cout << size3 << endl;
	return 0;
}
