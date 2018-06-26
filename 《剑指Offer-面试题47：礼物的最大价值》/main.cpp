#include <iostream>
#include <cmath>
using namespace std;

const int rows = 4;
const int cols = 4;

void disp(int **data, int rows, int cols){
	for(int i = 0;i < rows;i++){
		for(int j = 0;j < cols;j++){
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

int getMaxValue(int (*data)[cols], int rows, int cols){
	if(data == nullptr || rows <= 0 || cols <= 0){return 0;}
	int** maxValues = new int*[rows];
	for(int i = 0; i < rows;i++){
		maxValues[i] = new int[cols];
		memset(maxValues[i], 0, cols * sizeof(int));
	}	
	//TODO
	for(int i = 0;i < rows;i++){
		for(int j = 0;j <= i;j++){
			maxValues[i][0] += data[j][0];
		}
	}
	
	for(int j = 0;j < cols;j++){
		if(j != 0){//corner case
			for(int k = 0; k <= j;k++){
				maxValues[0][j] += data[0][k];
			}
		}
	}
	
	for(int i = 1;i < rows;i++){
		for(int j = 1; j < cols;j++){
			maxValues[i][j] = max( maxValues[i-1][j],maxValues[i][j-1]) + data[i][j];		
		}
	}
	disp(maxValues, rows, cols);	
	int maxValue = maxValues[rows - 1][cols - 1];
	for(int i = 0; i < rows; i++){delete[] maxValues[i];}
	delete[] maxValues;
	maxValues = nullptr;
	return maxValue;
}
int main(){
	int data[rows][cols] = {1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
	//TODO
	cout << getMaxValue(data, rows, cols) << endl;			
	return 0;
}
