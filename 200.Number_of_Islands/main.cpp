/***
 * DFS(Recursive)
 *
 * ***/
int numIslands(vector< vector<char> >& grid){
	if(grid.empty() || grid[0].empty()){return 0;}	
	int m = grid.size(), n = grid[0].size(), res = 0;
	vector< vector<bool> > visited(m, vector<bool>(n, false) );
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(grid[i][j] == '1' && !visited[i][j]){
				numIslandsDFS(grid, visited, i, j);
				++res;		
			}
		}
	}	
	return res;	
}

void numIslandsDFS(vector< vector<char> >& grid, vector< vector<bool> >& visited, int x, int y){
	if(x < 0 || x >= grid.size()){return;}
	if(y < 0 || y >= grid[0].size()){return;}
	if(grid[x][y] != '1' || visited[x][y]){return;}
	visited[i][j] = true;
	numIslandsDFS(grid, visited, x-1, y);
	numIslandsDFS(grid, visited, x+1, y);
	numIslandsDFS(grid, visited, x, y-1);
	numIslandsDFS(grid, visited, x, y+1);
}
