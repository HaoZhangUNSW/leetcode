int MoreThanHalfNum(int* numbers, int length){
	if(numbers == nullptr || length <= 0 ){return 0;}
	int start = 0;
	int end = length - 1;
	int index = partition(numbers, length, start, end);
	int mid = length >> 1;
	while(index != mid){
		if(index > mid){
			end = index - 1;
			index = partition(numbers, length, start, end);
		}else{
			start = index + 1;
			index = partition(numbers, length, start, end);
		}	
	}
	return numbers[mid];
}
