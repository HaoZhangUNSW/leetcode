#include <iostream>
using namespace std;
#define N 10000
struct Node{
      int parent; 
      int rank; //倒挂的树
};
Node UnionFindSet[N];

void init(int n);
int find(int x);
int find_(int x);
void merge(int x, int y);

int main(){
      int n = 20;
      init(n);
      merge(1, 5);
      merge(10, 13);
      merge(15, 17);
      merge(1, 13);
      merge(5, 17);
      merge(19, 18);
      if(find_(1) == find_(15)){
            cout<<"success1"<<endl;
      }
      return 0;
}

void init(int n){
      for(int i = 0; i < n; ++i){
            UnionFindSet[i].rank = 1;
            UnionFindSet[i].parent = i;
      }
}

int find(int x){
      //使用路径压缩之后的平均时间复杂度为O(1)
      int i = x;
      while(i != UnionFindSet[i].parent)
            i = UnionFindSet[i].parent;
      //压缩路径，将寻找X时经过的所有节点的父节点设为集合的根节点，方便下次查找
      int j = x;
      while(j != i){
            int tmp = UnionFindSet[j].parent;
            UnionFindSet[j].parent = i;
            j = tmp;
      }
      return i;
}

int find_(int x){
	if(UnionFindSet[x].parent != x){
		UnionFindSet[x].parent = find(UnionFindSet[x].parent);
	}
	return UnionFindSet[x].parent;
}
void merge(int x, int y){
	//平均时间复杂度为O(1)
      	//寻找树根(集合表示符)
      	x = find_(x);
      	y = find_(y);
      	if(y == x) return;
      	//将小树挂到大的树下面，可以减少较深节点的数目，维持树的平衡,以便高效查询
	//if(UnionFindSet[x].count > UnionFindSet[y].count){
        //    UnionFindSet[y].parent = x;
        //    UnionFindSet[x].count += UnionFindSet[y].count;
      	//}
      	//else{
        //   UnionFindSet[x].parent = y;
        //    UnionFindSet[y].count += UnionFindSet[x].count;
      	//}
	
      	if(UnionFindSet[x].rank > UnionFindSet[y].rank){
            UnionFindSet[y].parent = x;
            //UnionFindSet[x].count += UnionFindSet[y].count;
      	}
      	else if(UnionFindSet[x].rank < UnionFindSet[y].rank){
            UnionFindSet[x].parent = y;
            //UnionFindSet[y].count += UnionFindSet[x].count;
      	}else{
		UnionFindSet[y].parent = x;
		UnionFindSet[x].rank += 1;
	}
}
