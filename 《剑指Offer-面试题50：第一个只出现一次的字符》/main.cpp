/***
 * 给你N个数，其中有一个数只出现了一次，其余数均出现了两次，求那个出现一次的数是多少？
 * 注意：空字符串和nullptr
 *
 * ***/

#include <iostream>
using namespace std;

enum RESTYPE{valid=0, invalid};
int gFlag = invalid;

char FirstNotRepeating(char* pString){
	int res = 0;
	if(pString != nullptr){
		char* pCur = pString;
		while(*pCur != '\0'){
			res ^= ( *pCur );
			pCur++;
		}
		gFlag = valid;
	}
	return (char)res;
}

int main(){
	char* src0 = nullptr;
	char* src1 = "";
	char* src2 = "aba";
	//TODO
	char* testStr[] = {src0, src1, src2};
	int len = sizeof(testStr)/sizeof(char*);
	for(int i = 0; i < len;i++){
		char res_ = FirstNotRepeating(testStr[i]);
		if(gFlag == valid){
			cout << "valid: " << res_ << endl;
		}else{
			cout << "invalid: " << res_ << endl;
		}
	}
	return 0;
}
