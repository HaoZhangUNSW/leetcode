#include <stdio.h>

int str2int(const char* str){
	if(str == NULL){return 0;}
	int num = 0;
	while(*str != '\0'){num = 10*num + *str++ - '0';}
	return num;
}

int main(){
	printf("res=%d\n", str2int("123"));
	return 0;
}
