#include <iostream>
using namespace std;

#define N 1000
int UnionFindSet[N];

void init(int n);
int find(int x);
void merge(int x, int y, int n);

int main(){
	int n = 20;
      	init(n);
      	merge(1, 3, n);
      	merge(2, 3, n);
      	merge(4, 5, n);
      	merge(10, 13, n);
      	merge(4, 13, n);
      	if(find(1) == find(3)){
            cout<<"success1"<<endl;
      	}
      	if(find(5) == find(10)){
            cout<<"success2"<<endl;
      	}
      	if(find(1) != find(4)){
            cout<<"success3"<<endl;
      	}
      	return 0;
}

void init(int n){
	for(int i = 0; i < n; ++i)
        	UnionFindSet[i] = i;
}

int find(int x){
	return UnionFindSet[x];
}

void merge(int x, int y, int n){
	int set_id1 = UnionFindSet[x];
    	int set_id2 = UnionFindSet[y];
    	for(int i = 0; i < n; ++i)
        	if(UnionFindSet[i] == set_id1)
                	UnionFindSet[i] = set_id2;
}
