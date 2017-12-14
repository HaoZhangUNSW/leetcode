#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    int minus_gas = 0;
    int start_idx = 0;
    int neg_gas = 0;
    for(int i = 0; i < gas.size(); ++i){
        minus_gas += gas[i]-cost[i];
        if(minus_gas<0){
            neg_gas += minus_gas;
            minus_gas = 0;
            start_idx = i + 1;
        }
    }
    neg_gas += minus_gas;
    return neg_gas < 0 ? -1 : start_idx;
}

int canCompleteCircuit_(vector<int>& gas, vector<int>& cost) {
        vector<int> remainders;
        for (int i = 0; i < gas.size(); i++) {
            remainders.push_back(gas[i] - cost[i]);
        }
        int stationNums = gas.size();
        int sum = 0, begin = 0, end = 0;
        while (begin < stationNums) {
            while (end < (stationNums + begin) && sum >= 0) {
                sum += remainders[end % stationNums];
                end++;
            }
            //end = stationNums + begin
	    if (sum >= 0){//endPoint
                return begin;
            }
            //sum < 0
	    sum -= remainders[begin++];
        }
        return -1;
}

int main(){
	//vector<int> gas = {5, 4, 6, 2, 8, 7};
	//vector<int> cost = {3, 2, 11, 1, 6, 4};
	
	//vector<int> gas = {5, 7, 8, 2, 6, 4};
	//vector<int> cost = {3, 4, 6, 1, 11, 2};
	
	vector<int> gas = {7, 8, 2, 6, 4, 5};
	vector<int> cost = {4, 6, 1, 11, 2, 3};
	
    cout << canCompleteCircuit_(gas, cost) << endl;
	return 0;
}
