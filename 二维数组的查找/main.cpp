#include <iostream>
using namespace std;

bool find(int a[][4], int rows, int cols, int target){
	bool isFind = false;
	if(rows > 0 && cols > 0){
		int row = 0,col = cols - 1;	
		while(row <= rows && col >=0){
			if(a[row][col] == target){isFind=true;break;}
			else if(a[row][col] > target){col--;}
			else{row++;}
		}
	}
	return isFind;
}	

bool find_1(int a[][4], int rows, int cols, int target){
	bool isFind = false;
	if(rows > 0 && cols > 0){
		int row = rows-1,col = 0;	
		while(row >=0 && col <= cols){
			if(a[row][col] == target){isFind=true;break;}
			else if(a[row][col] > target){row--;}
			else{col++;}
		}
	}
	return isFind;
}	

bool find_2(int a[][4], int rows, int cols, int target){
	bool isFind = false;
	if(rows > 0 && cols > 0){
		int row = 0,col = cols - 1;	
		while(row <= rows && col >=0){
			if(a[row][col] == target){isFind=true;break;}
			else if(a[row][col] > target){col--;}
			else{row++;}
		}
	}
	return isFind;
}	
int main(){
	int a[][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	cout << find(a,3,4,12) << endl;
	return 0;
}
