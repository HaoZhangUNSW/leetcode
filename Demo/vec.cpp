#include <iostream>
#include <vector>
using namespace std;

int main(){
	int row_num = 3, col_num = 4;
	vector<int> ary(col_num, 0);
	for(auto it = ary.begin(); it != ary.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
