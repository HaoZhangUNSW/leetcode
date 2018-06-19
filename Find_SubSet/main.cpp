#include <iostream>
using namespace std;
int main(){
	int a[4] = {1, 2, 3, 4};
	//cout << sizeof(a) / sizeof(a[0]) << endl;
	int t = 1 << 4;
	int i, j, k;
	for(i = 0;i < t; i++){
		j = i;
		k = 0;
		cout << "{";
		while(j){
			if(j & 1){//判断最低位是否为1
				cout << a[k];
			}
			j >>= 1;//所有可能有1的位置都移动到最低位
			k++;//记录1的位置
		}	
		cout << "}";	
	
	}
	return 0;
}
