#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram0(string s, string t){
	if(s.length() != t.length() ){return false;}
	
	unordered_map<char, int> _counts;
	int n = s.length();
	for(int i = 0;i < n;i++){
		_counts[s[i]]++;
		_counts[t[i]]--;
	}
	for(auto& _count:_counts){
		if(_count.second){return false;}
	}		
	return true;
}

bool isAnagram(string s, string t){
	if(s.length() != t.length()){return false;}
	int n = s.length();
	int counts[26] = {0};
	for(int i = 0;i < n;i++){
		counts[s[i] - 'a']++;
		counts[t[i] - 'a']--;
	}
	for(int i = 0;i < 26;i++){
		if(counts[i]){return false;}
	}
	return true;
}

int main(){
	cout << isAnagram("car", "acr") << endl;
	return 0;
}
