#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& src, const string& separator){
	string str = src;
     	string substring;
     	string::size_type start = 0, index;
 	vector<string> dest;
	while(index != string::npos){
		index = str.find_first_of(separator,start);
         	if (index != string::npos){    
             		substring = str.substr(start,index-start);
             		dest.push_back(substring);
             		start = str.find_first_not_of(separator,index);
             		if (start == string::npos) break;
         	}
     	}
     	//the last token
     	substring = str.substr(start);
     	dest.push_back(substring);
	return dest;
}

int main(){
	string src = "zhp|matrix|love";
	string sep = ",";
	cout << string::npos << endl;
	int idx = src.find("matrix");
	if(idx == string::npos){
		cout << "False";
	}else{
		cout << "True";
	}
	vector<string> dest;
	dest = split(src, sep);
	vector<string>::iterator iter;
	for(iter = dest.begin();iter != dest.end();iter++){
		cout << *iter << endl;
	}
	//for(auto& str:dest){
	//	cout << str << "|";
	//}
	return 0;
}
