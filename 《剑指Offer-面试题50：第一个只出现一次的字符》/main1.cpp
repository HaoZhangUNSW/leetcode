#include <iostream>
#include <cassert>
using namespace std;

char getFirstOnceChar(char* str){
	//assert(str != nullptr);
	//if(*str == '\0'){return '\0';}
	
	const int num = 256;
	int hashTable[num] = {0};
	char* pCur = str;
	while(*pCur != '\0'){hashTable[*(pCur++)]++;}
	
	pCur = str;
	while(*pCur != '\0'){
		if(hashTable[*pCur] == 1){return *pCur;}
		pCur++;
	}
	return '\0';
}

int main(){
	char str[] = "abaccdeff";
	cout << getFirstOnceChar(str) << endl;
	return 0;
}
