#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int> >& triangle){
	int size = triangle.size();
	vector<int> minSum(triangle.back());
	for(int i = size - 2; i >= 0;i--){
		for(int j = 0; j <= i;j++){
			minSum[j] = min(minSum[j], minSum[j+1]) + triangle[i][j];
		}
	}	
	return minSum[0];
}

int main(){
	vector<vector<int> > triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
	cout << minimumTotal(triangle) << endl;
	return 0;
}
