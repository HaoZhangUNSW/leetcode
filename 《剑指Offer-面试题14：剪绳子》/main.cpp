#include <iostream>
using namespace std;

int getMaxProduct(int length){

   	//return results directly	
	if(length < 2){return 0;}
	if(length == 2){return 1;}
	if(length == 3){return 2;}

	//should not be results(a little tricky)
	int* products = new int[length+1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	
	int max;
	for(int i = 4;i <= length;i++){
		max = 0;
		//symmetric structure
		for(int j = 1;j <= i/2;j++){
			int product = products[j] * products[i-j];
			max = product > max ? product : max;
			products[i] = max;		
		}
	}
	max = products[length];	
	//delete array
	delete[] products;
	products = nullptr;
	return max;
}

int main(){
	int length0 = 8;
        int length1 = 0;
	int max0 = getMaxProduct(length0);
	int max1 = getMaxProduct(length1);
	cout << max0 << "," << max1 << endl;	
	return 0;
}
