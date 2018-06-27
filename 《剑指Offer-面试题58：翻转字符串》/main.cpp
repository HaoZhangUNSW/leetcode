
/***
 * C++中翻转字符串的三种方法：
 * 	https://blog.csdn.net/szu_aker/article/details/52422191
 *
 *
 * ***/

#include <iostream>
using namespace std;

void dispStr(char* str, int length){
	for(int i = 0;i < length;i++){
		cout << str[i] << " ";
	}
}

void Reverse(char* pBegin, char* pEnd){
	if(pBegin == nullptr || pEnd == nullptr){return;}
        while(pBegin < pEnd){
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}

char* ReverseSeq(char* str, int length){
	if(str == nullptr){return nullptr;}
	char* pBegin = str;
	char* pEnd = str + length-1;
	//cout << *pBegin << "," << *pEnd << endl;
	Reverse(str, str+length-2);	
	//dispStr(str, length);
	cout << endl;
	char* pBegin_ = str;
	char* pEnd_ = pBegin;
	//cout << *pBegin_ << "," << *pEnd_ << endl;
	while(*pBegin_ != '\0'){
		if(*pBegin_ == ' '){pBegin_++;pEnd_++;}	
		else if(*pEnd_ == ' ' || *pEnd_ == '\0'){
			Reverse(pBegin_, --pEnd_);
			pBegin_ = ++pEnd_;
		}else{
			pEnd_++;
		}	
	}
	return str;
}

int main(){
	char str[] = "i love you";
	int length = sizeof(str) / sizeof(char);
	ReverseSeq(str, length);	
	//Reverse(str, str+length-1);
	dispStr(str, length);
	return 0;
}
