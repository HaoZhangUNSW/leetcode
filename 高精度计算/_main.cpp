#include <iostream>
#include <string>
using namespace std;

string reverseStr(string input){
	string output = "";
	for(int i = 0;i < input.length();i++){
		output.insert(output.begin(), input[i]);
	}
	return output;
}
int charToInt(char c){return c - '0';}
char intToChar(int n){return n + '0';}


string sumofStr(string _s1, string _s2, int flag){
    string s1 = reverseStr(_s1);
    string s2 = reverseStr(_s2);
    int pMax = s1.length() > s2.length() ? s2.length() : s1.length();
    string sumStr = "";
    int p;
    int carry = 0;
    int temp = 0;
    for(p = 0; p < pMax; p++){
        temp = charToInt(s1[p]) + charToInt(s2[p]) + carry;
        carry = temp / flag;
        sumStr.insert(sumStr.begin(),intToChar(temp % flag));
    }
    if(p < s1.length()){
        for(; p < s1.length(); p++){
            temp = charToInt(s1[p]) + carry;
            carry = temp / flag;
            sumStr.insert(sumStr.begin(),intToChar(temp % flag));
        }
    }
    if(p < s2.length()){
        for(; p < s2.length(); p++){
            temp = charToInt(s2[p]) + carry;
            carry = temp / flag;
            sumStr.insert(sumStr.begin(),intToChar(temp % flag));
        }
    }
    
    //处理最高位
    if(carry > 0){
        sumStr.insert(sumStr.begin(),intToChar(carry % flag));
        //carry /= 10;
    }
    return sumStr;
}

int main(){
	//string a = "1234990000", b = "9026";
	string a = "101", b = "11";
	int flag = 2;
	cout << sumofStr(a, b, flag) << endl;
	return 0;
}
