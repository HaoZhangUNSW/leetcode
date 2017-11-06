#include <iostream>
#include <vector>
using namespace std;

       <int> plusOne(vector<int>& digits){
	int n = digits.size();
	
	// string="";
	vector<int> res;
	if(n == 0){return res;}	
	
	//sum的处理很关键，原地修改
	int sum = 1;
	for(int i = n - 1;i >=0;i--){
		sum += digits[i];
		digits[i] = sum % 10;
		sum /= 10;
	}
	
	//最高位的处理
	if(sum > 0){res.push_back(sum);}
	
	for(int i  = 0;i < n;i++){
		res.push_back(digits[i]);
	}
	return res;
}

int main(){
	int a[] = {9,9,9,9};
	vector<int>data(a, a + 4);
	data = plusOne(data);
	for(auto& elem: data){cout << elem << endl;}
	return 0;
}
