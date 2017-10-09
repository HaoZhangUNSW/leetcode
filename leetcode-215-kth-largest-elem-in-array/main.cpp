#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

bool cmp(const int& a,const int& b){
	return a > b;
}

int* getData(int len,int range){
	int * arr = new int[len];
	srand(unsigned(time(NULL)));
	for(int i = 0;i < len;i++){
		arr[i] = rand()%range;
	}
	return arr;
}
void disp(vector<int>& arr){
	vector<int>::iterator iter;
	for(iter = arr.begin();iter != arr.end();iter++){
		if(iter != arr.end() - 1){
			cout << *iter << ",";
		}else{
			cout << *iter;
		}
	}
	cout << endl;
}
int findKthLargest_1(vector<int>& arr,int k){
	sort(arr.begin(),arr.end(),cmp);
	cout << "after sorted:" << endl;disp(arr);
	return arr[k-1];
		
}

int partition(vector<int>& arr,int left,int right){
	int pivot = arr[left];
	int l = left + 1,r = right;
	while(l <= r){
		if(arr[l] < pivot && arr[r] > pivot){
			swap(arr[l++],arr[r--]);
		}
		if(arr[l] >= pivot){l++;}
		if(arr[r] <= pivot){r--;}
	}
	swap(arr[left],arr[r]);
	return r;
}
int findKthLargest_2(vector<int>& arr,int k){
	int left = 0,right = arr.size() - 1;
	while(true){
		int pos = partition(arr,left,right);
		if(pos == k - 1){return arr[pos];}
		if(pos > k -1){
			right = pos - 1;
		}else{
			left = pos + 1;
		}
	
	}

}

int findKthLargest_3(vector<int>& arr,int k){
	priority_queue<int> pq(arr.begin(),arr.end());
	for(int i = 0;i < k - 1;i++){
		pq.pop();
	}
	return pq.top();

}
int findKthLargest_4(vector<int>& arr,int k){
	multiset<int> mset;
	for(int i = 0;i < arr.size();i++){
		mset.insert(arr[i]);
		if(mset.size() > k){
			mset.erase(mset.begin());
		}
	}
	return *mset.begin();
}

int main(){
	int k=2,len = 10,range=100;
	int* data = getData(len,range);
	vector<int> arr(data,data+len);
	cout << "before sorted:" << endl;disp(arr);
	int res_4 = findKthLargest_4(arr,k);
	cout << "kth largest value:" << res_4;
	delete[] data;
	return 0;
}

