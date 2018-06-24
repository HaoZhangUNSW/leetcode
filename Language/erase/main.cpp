#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> data;
	data.push_back(40);
	data.push_back(20);
	data.push_back(20);
	data.push_back(50);
	data.push_back(60);
	vector<int>::iterator iter;
	for(iter = data.begin(); iter != data.end(); iter++){
		if(*iter == 20){data.erase(iter);}
	}
	/**
	iter = data.begin();
	while(iter != data.end()){
		if(*iter == 20){
			iter = data.erase(iter);
		}else{
			iter++;
		}
	}
	**/
	for(auto &elem : data){cout << elem << endl;}
	return 0;
}
