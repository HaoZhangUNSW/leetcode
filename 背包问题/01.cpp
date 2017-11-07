#include <iostream>
#include <algorithm>
using namespace std;

#define N 3
#define C 5

int main(){
	int value[N + 1] = {0, 60, 100,120};
	int weight[N + 1] = {0, 1,2,3};
	
	// cost[i][j]，背包容量为j的前提下，前i件宝贝的最大价值
	int f[N + 1][C + 1] = {0};
	for(int i = 1;i <= N;i++){
		//整数背包
		for(int j = 1;j <= C;j++){
			//边界条件
			if(j < weight[i]){f[i][j] = f[i-1][j];}
			else{
				f[i][j] = max( f[i-1][j], f[i-1][ j - weight[i] ] + value[i] );
			}
		}
		
	}

	cout << "打印最大价值获取路径:" << endl;
	for(int i = N;i >= 0;i--){
		for(int j = 0;j <= C;j++){
			printf("%4d ", f[i][j]);
		}
		cout << endl;
	}	
	
	cout << "打印物品重量和价值:" << endl;
	int i = N, j=C;
	while(i){
		if(f[i][j] == ( f[i-1][ j - weight[i] ] + value[i] )){
			cout << "weight: " << weight[i] << ",value: " << value[i] << endl;
			j -= weight[i];
		}
		i--;
	}	
	return 0;
}
