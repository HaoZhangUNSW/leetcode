#include <iostream>
#include <vector>
using namespace std;

int maxArea0(vector<int>& height){
	int _max = 0;
        for(int i = 0;i < height.size();i++){
            for(int j = i + 1;j < height.size();j++){
                int area = min(height[i], height[j])*(j-i);
                if(area >= _max){_max = area;}
            }
        }
        return _max;
}

int maxArea(vector<int>& height){
	//vector<int> tmp(height);
	//sort(height.begin(), height.end());
	//for(auto& elem: tmp){cout << elem;}
	//vector<int,int>data;
	//for(auto& elem: height){
		
	//}
	//int _max = 0;
	//int len = height.size();
	//for(int i = 0;i < len;i++){
	//		
	//}
	int water = 0;
	int i = 0,j = height.size()-1;
	while(i < j){
		int h = min(height[i], height[j]);
		//666
		water = max(water, (j-i)*h);
		//在来似曾相识，不对数组做预先排序。
		while(height[i] <= h && i < j){i++;}
		while(height[j] <= h && i < j){j--;}	
	}
	return water;
}

int main(){
	int data[] = {1,4,2,7,4,9};
	vector<int> _data(data, data + sizeof(data)/sizeof(data[0]));
	cout << maxArea(_data);	
	return 0;
}
