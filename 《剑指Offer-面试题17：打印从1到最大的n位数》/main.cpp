/***
 * 全排列，写十遍。 
 *
 * ***/

void printNumber(int n){
	if(n <= 0){return;}
	char* number = new[n+1];
	number[n] = '\0';
	for(int i = 0;i < 10;i++){
		number[0] = i + '0';
		printNumberRecur(number, n, 0);
	}
	delete[] number;
}


void printNumberRecur(char* number, int length, int index){
	if(index == length - 1){
		print(number);
		return;
	}
	for(int i = 0;i < 10;i++){
		number[index+1] = i + '0';
		printNumberRecur(number, length, index + 1);
	}

}
