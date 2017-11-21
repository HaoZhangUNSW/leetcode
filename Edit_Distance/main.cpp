#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string& word1, string& word2){
	int word1Len = word1.length();
	int word2Len = word2.length();
	vector<vector<int> > results(word1Len+1, vector<int>(word2Len+1, 0));
	for(int i = 0;i <= word1Len;i++){results[i][0] = i;}	
	for(int j = 0;j <= word2Len;j++){results[0][j] = j;}
	for(int i = 1;i <= word1Len;i++){
		for(int j = 1;j <= word2Len;j++){
			if(word1[i-1] == word2[j-1]){
				results[i][j] = results[i-1][j-1];
			}else{
				results[i][j] = min(results[i][j-1],
						min(results[i-1][j],results[i-1][j-1])) + 1;
			}	
		}
	}
	return results[word1Len][word2Len];	
}

/**
 *	Can the idea work with 2D array(word1Len, word2Len)?
 *	don not work well!
 */
int minDistance1(string word1, string word2){
	int word1Len = word1.length();
	int word2Len = word2.length();
	vector<vector<int> > results(word1Len, vector<int>(word2Len, 0));
	
	//空串
	if(word1Len == 0){return word2Len;}
	if(word2Len == 0){return word1Len;}	
	
	//边界
	for(int i = 0;i <= word2Len;i++){results[0][i] = i;}
	for(int j = 0;j <= word1Len;j++){results[j][0] = j;}

	for(int i = 1;i < word1Len;i++){
		for(int j = 1;j < word2Len;j++){
			if(word1[i] == word2[j]){
				results[i][j] = results[i-1][j-1];
			}else{
				results[i][j] = min(results[i][j-1],
						min(results[i-1][j],results[i-1][j-1])) + 1;
			}	
		}
	}
	return results[word1Len-1][word2Len-1];	
}

int main(){
	string word1 = "matrix";
	string word2 = "zhpmat";
	cout << minDistance(word1, word2) << endl;
	return 0;
}
