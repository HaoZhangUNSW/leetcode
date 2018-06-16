/***
 * 回文子序列 != 回文子字符串
 *
 *https://www.cnblogs.com/grandyang/p/6493182.html?utm_source=itdadao&utm_medium=referral
 * ***/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int find_longest_string(string s){
	int n = s.size();
	
	//null string
	if(n == 0){return 0;}
	
	vector< vector<int> > dp(n, vector<int>(n));
	for(int i = n - 1;i >= 0 ; i--){
		//boundary condition 
		dp[i][i] = 1;
		for(int j = i + 1; j < n; j++){
			if(s[i] == s[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}else{
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}//for
	}//for
	return dp[0][n-1];
}
int main(){
	string s0 = "bbbab";
	string s1 = "";
	//TODO
	cout << find_longest_string(s0) << endl;//4
	cout << find_longest_string(s1) << endl;//0
	return 0;
}
