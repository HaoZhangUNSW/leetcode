/***
 *
 *	同时找出max和sec.
 *
 * ***/
#include <iostream>
using namespace std;
int main(){
	int num = 5;
	int a[] = {6,3,2,10,9};
	int max = a[0];
	int sec = -32767;
	int temp = 0;
	for(int i = 1;i < num;i++){
		if(a[i] > max){
			temp = max;
			max = a[i];
		}
		if(temp > sec){sec = temp;}	
	}
	cout << sec << endl;
	return 0;
}
