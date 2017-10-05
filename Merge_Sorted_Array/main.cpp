#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while(i >= 0 && j >=0){
			if(nums1[i] > nums2[j]){
				nums1[k--] = nums1[i--];	
			}else{
				nums1[k--] = nums2[j--];
			}
		}
		while(j >= 0){
			nums1[k--] = nums2[j--];
		}
}
};

int main(){
	int a[] = {4,5,6,7,8,9};
	int b[] = {1,2,3};
	vector<int> nums1(a, a + 6);
	nums1.resize(6+3);
	vector<int> nums2(b, b + 3);
	Solution slu;
	slu.merge(nums1,6, nums2,3);
	vector<int>::iterator iter;
	for(iter = nums1.begin();iter != nums1.end();iter++){
		cout << * iter << endl;
	}
	return 0;
}

