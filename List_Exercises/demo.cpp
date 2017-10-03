#include<iostream>
using namespace std;
void getLen(int* ary){
	//return sizeof(ary) / sizeof(ary[0]);
	for(int i = 0;i < 3;i++){
		cout << ary[i] << " ";
	}
}
int main(){
	int ary[] = {1,2,3};
	cout << sizeof(ary) / sizeof(ary[0]) << endl;
	getLen(ary);
	return 0;
}
