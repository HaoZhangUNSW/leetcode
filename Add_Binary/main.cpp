// Example program
#include <iostream>
#include <string>
using namespace std;

string reverseStr(string input){
    string output = "";
    for(int i = 0; i < input.length(); i++){
        output.insert(output.begin(),input[i]);
    }
    return output;
}

string to_binary(int a){
    string _a = to_string(a);
    string r_a = reverseStr(_a);
    string rst = "";
    for(int i = 0;i < r_a.length();i++){
        // get current elem and convert char to int
        int prev = r_a[i] - '0';
        if(prev >= 2){
            if( (i + 1) < r_a.length() ){
                int next = r_a[i+1] - '0';
                prev -= 2;
                next += 1;
                r_a[i] = char(prev +'0');
                r_a[i+1] = char(next +'0');
                rst.insert(rst.begin(),r_a[i]);
            }else{
                    prev -= 2;
                    r_a[i] = char(prev +'0');
                    rst.insert(rst.begin(), r_a[i]);
                    rst.insert(rst.begin(), '1');
            }
        }else{
            rst.insert(rst.begin(), r_a[i]);
        }
            
    }
    return rst;
}

string addBinary(string a, string b){
           long long int _a = stoi(a), _b = stoi(b), sum;
           sum = _a + _b;
           return to_binary(sum);
}

int main(){
  string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
  string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
  cout << addBinary(a, b) << endl;
  return 0;
}
