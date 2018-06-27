/***
 * 用一维数组来表示二维数组
 *
 * ***/
bool IsExist(int* matrix, int rows, int cols, int target){
	bool found = false;
	if(matrix != nullptr && rows > 0 && cols > 0){
		int row = 0;
		int col = cols - 1;
		while(row < rows && col >= 0){
			if(matrix[row * cols + col] == target){
				found = true;
				break;
			}else if(matrix[row * cols + col] > target){
				--col;
			}else{
				++row;
			}		
		}			
	}
	return found;
}
