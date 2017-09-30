#include <stdio.h>
char func(char* pString){
	if(pString == NULL){ return '\0';}
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for(unsigned int i = 0;i < tableSize;i++){hashTable[i] = 0;}

	char* pHashKey = pString;
	while(*pHashKey != '\0'){hashTable[*(pHashKey++)]++;}
	
	pHashKey = pString;
	while(*pHashKey != '\0'){
		if(hashTable[*pHashKey] == 1){return *pHashKey;}
		// classic paradigm
		pHashKey++;
	}
	return '\0';
}
int main(){
	char* str= "abaccdeff";
	printf("%c",func(str));
	return 0;
}
