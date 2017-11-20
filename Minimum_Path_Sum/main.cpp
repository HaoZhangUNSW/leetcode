/**
 *	desc: minimum path sum#64
 *	author: zhpmatrix
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/** dp idea **/
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


int findPath(vector<vector<int> >& grid, int rowIdx, int colIdx){
	if(rowIdx == 0 && colIdx == 0){return grid[rowIdx][colIdx];}
	if(rowIdx == 0){return findPath(grid, 0, colIdx -1) + grid[0][colIdx];}
	if(colIdx == 0){return findPath(grid, rowIdx - 1, 0) + grid[rowIdx][0];}
	return min(findPath(grid, rowIdx - 1, colIdx), findPath(grid, rowIdx, colIdx - 1)) + grid[rowIdx][colIdx];
}

/** recursive search **/
int minPathSum1(vector<vector<int> >& grid){
	int rows = grid.size();
	int cols = grid[0].size();
	return findPath(grid, rows-1, cols-1);
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
	cout << minPathSum1(_grid) << endl;
	return 0;
}
