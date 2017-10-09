#include <iostream>
#include <vector>
using namespace std;
int heap_size = 0;
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
int left(int idx){return (idx << 1) + 1;}
int right(int idx){return (idx << 1) + 2;}
void max_heapify(vector<int>& arr,int idx){
	int largest = idx;
	int l = left(idx),r = right(idx);
	if(l < heap_size && arr[l] > arr[largest]){largest=l;}
	if(r < heap_size && arr[r] > arr[largest]){largest=r;}
	if(largest != idx){
		swap(arr[idx],arr[largest]);
		max_heapify(arr,largest);
	}
}
void build_max_heap(vector<int>& arr){
	heap_size = arr.size();
	for(int i = (heap_size >> 1) - 1;i >= 0;i--){
		max_heapify(arr,i);
	}
}
int findKthLargest(vector<int>& arr,int k){
	build_max_heap(arr);
	cout << "after sorted:" << endl;disp(arr);
	for(int i = 0;i < k;i++){
		swap(arr[0],arr[heap_size - 1]);
		heap_size--;
		max_heapify(arr,0);
	}
	return arr[heap_size];
}
int main(){
	int k=2,len=10,range=100;
	int* data = getData(len,range);
	vector<int> arr(data,data+len);
	cout << "before sorted:" << endl;disp(arr);
	int res = findKthLargest(arr,k);
	cout << "kth largest value:" << res;
	delete[] data;
	return 0;
}
