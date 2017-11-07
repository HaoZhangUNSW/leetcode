#include <iostream>
#include <string>
using namespace std;
const int MAXN = 100;

int main(){
	int n, V;
    	int f[MAXN];
	int _f[MAXN][MAXN];
    	int w[MAXN], p[MAXN];
	while(cin>>n>>V){
        	if(n == 0 && V == 0)
            		break;

        	memset(f, 0, sizeof(f));
       		memset(w, 0, sizeof(w));
        	memset(p, 0, sizeof(p));

        	for(int i = 1; i <= n; ++i)
            		cin>>w[i]>>p[i];

      		for(int i = 1; i <= n; i++){
            		for(int v = V; v >= w[i]; v--){
                		f[v] = max(f[v], f[v-w[i]]+p[i]);
            		}
        	}
        	cout<<f[V]<<endl;
			
		//for(int i = 1;i <= n;i++){
		//	//2
		//	//for(int j = 1;j <= V;j++){
		//		//if(j < w[i]){_f[i][j] = _f[i][j-1];}
		//		//else{
		//		//	_f[i][j] = max(_f[i-1][j], _f[i-1][j - w[i]]+p[i]);
		//		//}
		//	//}
		//	
		//	//3
		//	for(int j = w[i]; j <= V;j++){
		//			_f[i][j] = max(_f[i-1][j], _f[i-1][ j - w[i] ] + p[i]);
		//		
		//		}
		//	}
		//
		//cout << _f[n][V] << endl;	
	}
    	return 0;
}
