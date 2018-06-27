bool duplicate(int* number, int length, int* duplication){
	if(number == nullptr || length <= 0){return false;}	
	for(int i = 0;i < length;i++){
		while(number[i] != i){
			if(number[i] == number[number[i]]){
				*duplication = number[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
}
