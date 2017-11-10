#include <iostream>
#include <unordered_map>
using namespace std;
string minWindow(string s, string t) {
        if(s == "" || t == ""){return "";}
        map<char, int> count;
        typedef map<char, int>::iterator iter;
        string rst = "";
        int max = INT_MAX;
        //对t的字符以及频数统计(这种思路忽略了元素之间的先后顺序)
        for(int i = 0;i < t.length();i++){count[t[i]]++;}
        //show(count);
        for(int i = 0;i < s.length();i++){
                map<char,int> tmp;
                tmp[s[i]] = 1;
                for(int j = i+1;j < s.length();j++){
                        tmp[s[j]]++;
                        bool flag = false;
                        for(iter it = count.begin();it != count.end();it++){
                            if(tmp.find(it->first) == tmp.end() ||
                              tmp[it->first] != count[it->first]){
                                flag = true;
                            }
                        }                 
                        if(!flag){
                            if(tmp.size() < max){
                                max = tmp.size();
                                cout << "max: " << max << "," << i << "," << j << endl;
                                rst = s.substr(i,j+1);
                            }
                        }
                }
            }
        return rst;
    }
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string str = "";
    if(str == ""){cout << "str is empty!" << endl;}
    cout << minWindow(s,t) << endl;
    std::cout << "Hello World!\n";
}