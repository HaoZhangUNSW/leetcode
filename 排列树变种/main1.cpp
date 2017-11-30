#include <iostream>
#define N 3
int x[N+1] = {0, 1, 2, 3};
void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void backtrace(int t){
	if(t > N){
		for(int i = 1;i <= N;i++){printf("%d",x[i]);}
		printf("\n");
	}else{
		for(int i = t;i <= N;i++){
			swap(x[t], x[i]);
			backtrace(t+1);
			swap(x[t], x[i]);
		}
	
	}	
}
int main(){
	backtrace(1);
	return 0;
}
