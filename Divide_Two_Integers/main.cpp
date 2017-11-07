#include <iostream>
using namespace std;

// Do not AC!!!
int divide(int dividend, int divisor) {
	int a = abs(dividend);
        int b = abs(divisor);
        int res = 0;
        while(a >= b){
             int start = b;
             while(a > 0){
                 a -= start;
                 res += 1;
             }
        }
    return ((dividend^divisor)>>31) ? (-res) : (res);  //取双方的符号位！
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1)){return INT_MAX;}
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        
        //TLE
        //int res = 0;
        //while(dvd >= dvs){
        //     dvd -= dvs;
        //     res += 1;
        //}
        
        //second version
        //int res = 0;
        //while(dvd >= dvs){
        //    long long tmp = dvs, multi = 1;
        //    while(dvd >= (tmp << 1)){
        //        tmp <<= 1;
        //        multi <<= 1;
        //    }
        //    dvd -= tmp;
        //    res += multi;
        //}
        
        //third version
        int res = 0;
        while(dvd >= dvs){
            long long tmp = dvs,multi=1;
            //改用bit manipulation, 明显加快速度!!!
            for(;(tmp<<1) <= dvd;tmp <<= 1){
                multi <<= 1;
            }
            dvd -= tmp;
            res += multi;
        }
        return ((dividend^divisor)>>31) ? (-res) : (res);  //取双方的符号位！
}
};
int main(){
	cout << divide(0,3) << endl;
	return 0;
}
