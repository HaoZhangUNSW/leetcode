#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector< vector<int> >& matrix){
	reverse(matrix.begin(), matrix.end());
	for(int i = 0;i < matrix.size();i++){
		for(int j = i + 1;j < matrix[i].size();j++){
			swap(matrix[i][j], matrix[j][i]);	
		}
	}
}
int main(){
	int M=3,N=3;
	vector<vector<int> > matrix;
	for(int i = 0;i < M;i++){
		vector<int> row;
		for(int j = 0;j < N;j++){
			row.push_back(i+j);
		}
		matrix.push_back(row);
	}
	rotate(matrix);	
	return 0;
}
