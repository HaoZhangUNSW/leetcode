#include <iostream>
using namespace std;


bool verify(int* data, int length){
	if(data == nullptr || length <= 0){return false;}
	
	int root = data[length-1];
	int i = 0;
	for(;i < length - 1;i++){
		if(data[i] > root){break;}
	}
	int j = i;
	for(;j < length - 1;j++){
		if(data[j] < root){return false;}	
	}
	//int numOfLeftNode = left + 1;
	//int numOfRightNode = right - left;
	
	//int Left[numOfLeftNode] = {0};
	//int Right[numOfRightNode] = {0};
	//for(int i = 0;i <= left;i++){Left[i] = data[i];}
	//for(int i = left+1;i <= right;i++){Right[i] = data[i];}
	bool leftTag = true;
	if(i > 0){	
		leftTag = verify(data, i);
	}
	bool rightTag = true;
	if(i < length -1){	
		rightTag = verify(data+i, length-i-1);
	}
	return (leftTag && rightTag);
	//bool leftTag = verify(Left, numOfLeftNode);
	//bool rightTag = verify(Right, numOfRightNode);
	//return leftTag && rightTag;
}
int main(){
	int seq0[] = {5,12,6,9,11,10,8};
	int seq1[] = {5,9,6,9,11,10,8};
	int len0 = sizeof(seq0) / sizeof(int);
	int len1 = sizeof(seq1) / sizeof(int);
	cout << verify(seq1, len1) << endl;
	return 0;
}
