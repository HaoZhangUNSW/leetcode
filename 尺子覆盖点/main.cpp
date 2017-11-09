#include <iostream>
using namespace std;

int cal(int* arr, int num, int len){
	if(arr == NULL || num <=0 || len <= 0 ){
		return 0;
	}
	int max = 0;
	int front = 0;
	int rear = num - 1;
	while(rear >= 0){
		front = rear;
		while(front >=0){
			if(arr[rear] - arr[front] <= len){
				front--;
			}else{
				break;
			}
		}
		max = rear -front > max ? rear - front:max;
		rear--;
	}
	return max;
}

int cal_1(int* arr, int num, int len){
	if(arr == NULL || num <= 0 || len <= 0){
		return 0;
	}
	int max = 0;
	int front = 0;
	int rear = num - 1;
	while(front < num){
		rear = front;
		while(rear < num){
			if(arr[rear] - arr[front] <= len){
				rear++;
			}else{
				break;
			}
		}
		max = rear - front > max ? rear - front:max;
		front++;
	}
	return max;
}
int main(){
	int len = 4;
	int arr[] = {1,3,7,8,9,11};
	cout << cal_1(arr, sizeof(arr)/sizeof(arr[0]), len);
	return 0;
}
