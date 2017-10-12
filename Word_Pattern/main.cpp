#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;
//vector<string> split(const string& src, const string& separator){
//    string str = src;
//    string substring;
//    string::size_type start = 0, index;
//    vector<string> dest;
//    while(index != string::npos){
//        index = str.find_first_of(separator,start);
//        if (index != string::npos){    
//                substring = str.substr(start,index-start);
//                dest.push_back(substring);
//                start = str.find_first_not_of(separator,index);
//                if (start == string::npos) break;
//        }
//    }
//    substring = str.substr(start);
//    dest.push_back(substring);
//    return dest;
//}
////bool wordPattern0(string pattern, string str){
//	vector<string> res = split(str, " ");	
//	for(int i = 0;i < pattern.size();i++){
//		//TODO			
//	}
//	return false;
//}

bool wordPattern(string pattern, string str){
	map<char, int> p2i;
	map<string, int> w2i;
	istringstream in(str);
	string word;
	int n = pattern.size();
	int i = 0;
	while(in >> word){
		if(i == n || p2i[pattern[i]] != w2i[word]){return false;}
		p2i[pattern[i]] = w2i[word] = i + 1;
		++i;
	}	
	return i == n;
}

int main(){
	cout << wordPattern("abbb","dog cat cat dog");
	return 0;
}
