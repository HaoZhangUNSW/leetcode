#include <iostream>
#define N 3
int x[N+1];
void backtrace(int t){
	if(t > N){
		for(int i = 1;i <= N;i++){printf("%d",x[i]);}
		printf("\n");
	}else{
		for(int i = 0;i <= 1;i++){
			x[t] = i;
			backtrace(t+1);
		}
	
	}	
}
int main(){
	memset(x, 0, (N+1)*sizeof(int));
	backtrace(1);
	return 0;
}
