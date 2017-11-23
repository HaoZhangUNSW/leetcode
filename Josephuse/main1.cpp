#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<int> Numbers;   //vector containing numbers

	Numbers.push_back(10);
	Numbers.push_back(20);
	Numbers.push_back(10); 
	Numbers.push_back(15);
	Numbers.push_back(12);
	Numbers.push_back(7);
	Numbers.push_back(9);
	Numbers.push_back(10);

	vector<int>::iterator  it;

	cout << "Before calling remove" << endl << "Numbers { " ;

	for(it = Numbers.begin(); it != Numbers.end(); it++)
	{
		cout << *it << "\t" ;
	}
	cout << " }\n" << endl ;

	Numbers.erase(remove(Numbers.begin(), Numbers.end(), 10), Numbers.end());

	/** 会出现重复的7,9 **/
	// remove all elements from Numbers that match 10
	//vector<int>::iterator ret = remove(Numbers.begin(), Numbers.end(), 10) ;
	
	/** 最后一个1删除不掉 **/
	//for(it = Numbers.begin();it != Numbers.end();it++){
	//	if(*it == 10){
	//		it = Numbers.erase(it);
	//	}else{
	//		it++;
	//	}
	//}
	//cout << "After calling remove" << endl<< "Numbers { " ;
	for(it = Numbers.begin(); it != Numbers.end(); it++)
	{
		cout << *it << "\t" ;
	}
	cout << " }\n" << endl ;

	//cout << "Total number of elements removed from Numbers = "
	//		<< Numbers.end() - ret << endl ;

	//cout << "Valid elements of Numbers { " ;
	//for(it = Numbers.begin(); it != ret; it++)
	//{
	//	cout << *it << "\t" ;
	//}
	//cout << " }\n" << endl ;

}
