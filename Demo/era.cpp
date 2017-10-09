#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(vector<int>& data){
	cout << "-------------------"<< endl;
	vector<int>::iterator iter;
	for(iter = data.begin();iter != data.end();iter++){
		cout << *iter << " " << endl;
	}
}
int main(){
	int number[] = {10,10,10,15,12,9,8};
	vector<int> numbers(number, number + 7);
	show(numbers);
	//vector<int>::iterator ret = remove(numbers.begin(), numbers.end(), 10);
	//show(numbers);	
	//cout << "Total number: " << numbers.end() - ret << endl;
	
	for(vector<int>::iterator it = numbers.begin(); it != numbers.end();){
		if(*it == 10){
			it=numbers.erase(it);
			//Not work!
			//numbers.erase(it++);
		}else{
			it++;
		}
	}
	show(numbers);	
	return 0;
}
