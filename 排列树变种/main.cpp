#include <iostream>
#include <vector>
using namespace std;

void ouput(vector<int>& s,int k) {
    for (int j = 1; j <= k; j++)
        cout << s[j] << " " ;
    cout << endl;
}

void for_loop(vector<int>& s,int n,int k,int l) {
     for (s[l] = s[l-1]+1; s[l] < n; s[l]++) {
         if (l == k) {
             ouput(s,k);
         } else {
            for_loop(s,n,k,l+1);
         }
     }
               
}

void for_loop_norec(vector<int>& s,int n,int k,int l) { 
    s[l] = 0;   //s[1] = 0;
    while (l) {
        while(s[l] < n) {       //处理当前层
            if (l == k){        //到达最低层，打印结果
                ouput(s,k);
                s[l] += 1;      //
            } else {            //否则深度优先，进入下一层
                l += 1;
                s[l] = s[l-1] +1;
            }
        }
        l--;                 //下面的处理完了，跳回上一层
        s[l] += 1;           //to the next pos on this level
    }
}

int main() {
	int n = 6;
    	int k = 3;
    	vector<int> s(n + 1,-1);
	for_loop(s,n,k,1);
	cout << "No rec version" << endl;
	for_loop_norec(s, n, k, 1);
	return 0;
}
