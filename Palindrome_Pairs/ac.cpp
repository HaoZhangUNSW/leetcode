#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
       	unordered_map<string, int> m;
        set<int> s;
        //空间换时间
	for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); ++i) {
            string t = words[i];
            int len = t.size();
            reverse(t.begin(), t.end());
	    //镜面对称
	    if (m.count(t) && m[t] != i) {
                res.push_back({i, m[t]});
            }
            //镜面不对称
	    auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                //aabcd & dcb 
		if (isValid(t, 0, len - d - 1) && m.count(t.substr(len - d))) {
                    res.push_back({i, m[t.substr(len - d)]});
                }
		
		//abcdd & cba
                if (isValid(t, d, len - 1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            
	    }//for
        }//for
        return res;
    }
    
    //判断是否是回文串
    bool isValid(string t, int left, int right) {
        while (left < right) {
            if (t[left++] != t[right--]) return false;
        }
        return true;
    }
};

int main(){
	vector<vector<int> > rst;
	//vector<string> words = {"bat", "tab", "cat"};
	vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
	Solution slu;
	rst = slu.palindromePairs(words);
	for(auto vec:rst){
		for(auto elem: vec){
			cout << elem << endl;
		}
	}
}
