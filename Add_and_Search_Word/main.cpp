#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class WordDictionary{
	public:
		WordDictionary(){}
		void addWord(string word){
			setDict.insert(word);
			//dict.push_back(word);
		}
		bool isExist(string word){
			if(setDict.find(word) != setDict.end()){
				return true;
			}
			//for(auto _word: dict){
			//	if(_word == word){return true;}
			//}
			return false;
		}
		void backtrack(string word, int dep, int pos){
			cout << dep << "," << pos << endl;
			if(isExist(word)){flag=true;return;}
			if(dep == word.size()){return;}
			if(word[pos] == '.'){
				for(int i = 0;i < 26;i++){
					word[pos] = 'a' + i;
					backtrack(word, dep+1, pos+1);
				}
			}else{
				backtrack(word, dep+1, pos+1);
			}	
		}
		bool search(string word){
			flag = false;
			backtrack(word, 0, 0);
			return flag ? true : false;
		}		

	private:
		vector<string> dict;
		set<string> setDict;
		bool flag;
};

int main(){
	WordDictionary obj;
	vector<string> words={"bad","dad","mad"};
	for(auto word:	words){obj.addWord(word);}
	vector<string> rgxs = {"cad","pad","mad","b.m"};
	for(auto rgx:	rgxs){
		cout << "-----------------------" << endl;
		cout << obj.search(rgx) << endl;
		cout << "-----------------------" << endl;
	}
	return 0;
}
