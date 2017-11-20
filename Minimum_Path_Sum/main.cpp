#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int> >& grid){
	const int rows = grid.size();
	const int cols = grid[0].size();
	vector<vector<int> > results(grid);
	for(int j = 1;j < cols;j++){results[0][j] = results[0][j-1] + grid[0][j];}
	for(int i = 1;i < rows;i++){results[i][0] = results[i-1][0] + grid[i][0];}
	for(int i = 1;i < rows;i++){
		for(int j = 1;j < cols;j++){
			results[i][j] = min(results[i-1][j], results[i][j-1]) + grid[i][j];	
		}
	}	
	return results[rows-1][cols-1];
}


int main(){
	const int rows = 3, cols = 3;
	int grid[][cols] = {1, 3, 1,
			    1, 5, 1,
			    4, 2, 1};
	vector<vector<int> > _grid(3, vector<int>(3, 0));
	for(int i = 0;i < rows;i++){
		for(int j = 0;j < cols;j++){
			_grid[i][j] = grid[i][j];
		}
	}
	cout << minPathSum(_grid) << endl;
	return 0;
}
