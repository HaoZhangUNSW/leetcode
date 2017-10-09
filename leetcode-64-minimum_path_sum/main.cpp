#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void disp(vector<vector<int> >& grid){
	int m = grid.size();
	int n = grid[0].size();
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
}

int minPathSum_1(vector<vector<int> >& grid){
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > sum(m,vector<int>(n,grid[0][0]));
	cout << "sum:" << endl; disp(sum);
	
	//col bound
	for(int i = 1;i < m;i++){
		sum[i][0] = sum[i-1][0]+grid[i][0];
	}
	
	//row bound
	for(int j = 1;j < n;j++){
		sum[0][j] = sum[0][j-1]+grid[0][j];
	}
	
	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;j++){
			sum[i][j] = min(sum[i-1][j],sum[i][j-1])+grid[i][j];
			
		}
	}
	return sum[m-1][n-1];
}

int minPathSum_2(vector<vector<int> >& grid){
	int m = grid.size();
	int n = grid[0].size();
	vector<int> pre(m,grid[0][0]);
	vector<int> cur(m,0);
	for(int i = 1;i < m;i++){
		pre[i] = pre[i-1] + grid[i][0];
	}
	for(int j = 1;j < n;j++){
		cur[0] = pre[0] + grid[0][j];
		for(int i = 1;i < m;i++){
			cur[i] = min(cur[i-1],pre[i])+grid[i][j];
		}
		swap(pre,cur);
	
	}
	return pre[m-1];

}
int minPathSum_3(vector<vector<int> >& grid){
	int m = grid.size();
	int n = grid[0].size();
	vector<int> cur(m,grid[0][0]);
	for(int i = 1;i < m;i++){
		cur[i] = cur[i-1] + grid[i][0];
	}
	for(int j = 1;j < n;j++){
		cur[0] += grid[0][j];
		for(int i = 1;i < m;i++){
			cur[i] = min(cur[i-1],cur[i])+grid[i][j];
		}
	}
	return cur[m-1];
}
int main(){
	int m=5,n=3;
	vector<vector<int> > grid;
	for(int i = 0;i < m;i++){
		vector<int> tmp;
		for(int j = 0;j < n;j++){
			tmp.push_back(rand()%6);
		}
		grid.push_back(tmp);
	}	
	cout << "grid:" << endl;disp(grid);
	cout << "res:" << endl;cout << minPathSum_3(grid) << endl;
	return 0;
}
