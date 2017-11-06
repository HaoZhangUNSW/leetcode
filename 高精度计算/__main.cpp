#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b, int flag){
        string s = "";
        int c = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1){//c == 1保证最高位的进位能够加上
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            // c%2 + '0' 表示进位之后的结果
            s = char(c % flag + '0') + s;
            // c表示进位（考虑上边代码c +=...）
            c /= flag;
        }
        return s;
}

int main(){
	string a = "101", b = "11";
	int flag = 10;
	cout << addBinary(a, b, flag) << endl;
	return 0;
}
