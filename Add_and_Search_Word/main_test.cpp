#include <iostream>
#include <vector>
#include <string>
using namespace std;

class WordDictionary{
	public:
		WordDictionary(){count = 0;
			flag = false;
		}
		void addWord(string word){dict.push_back(word);}
		bool isExist(string word){
			for(auto _word: dict){
				if(_word == word){return true;}
			}
			return false;
		}
		void backtrack(string word, int dep, int pos){
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
			//flag = false;
			backtrack(word, 0, 0);
			return flag ? true : false;
		}		
		void addCount(){

			count++;
		}
		void func(int tag){
			if(tag < 2){
				flag = true;
			}
		}
		int getCount(int tag){
			func(tag);
			return flag ? true : false;
			};
	private:
		vector<string> dict;
		bool flag;
		int count;
};

int main(){
	WordDictionary obj;
//	vector<string> words={"bad","dad","mad"};
//	for(auto word:	words){obj.addWord(word);}
//	vector<string> rgxs = {"cad","pad","mad","b.m"};
//	for(auto rgx:	rgxs){
//		cout << "-----------------------" << endl;
//		cout << obj.search(rgx) << endl;
//		cout << "-----------------------" << endl;
//	}
	//int i = 0;
	//obj.addCount();
	cout << obj.getCount(4) << endl;
	cout << obj.getCount(3) << endl;
	cout << obj.getCount(0) << endl;
	return 0;
}
