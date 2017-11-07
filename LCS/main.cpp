#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCS(string a, string b){
	int alen = a.length(), blen = b.length();
	
	//默认初始化为0	
	int f[alen+1][blen+1];
	
	for(int i = 1;i <= alen;i++){
		for(int j = 1;j <= blen;j++){
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if(a[i-1] == b[j-1]){f[i][j] = f[i-1][j-1]+1;}		
		}
	}
	return f[alen][blen];
}

int main(){
	string a = "abcde",b = "cdmf";
	cout << LCS(a,b)<< endl;
	return 0;
}
