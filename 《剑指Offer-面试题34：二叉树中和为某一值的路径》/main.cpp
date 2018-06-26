struct BinaryTreeNode{
	int m_nValue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}

void FindPath(BinaryTreeNode* pRoot, int number){
	//boundary condition
	if(pRoot == nullptr){return;}
	
	//results structure
	vector<int> path;
	
	//initial results
	int curNum = 0;

	FindPath(pRoot, number, path, curNum);
}


void FindPath(BinaryTreeNode* pRoot, int number, vector<int> path, int curNum){

	curNum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);	
	
	bool isLeaf = (pRoot->m_pLeft == nullptr) && (pRoot->m_pRight == nullptr);
	if(curNum == number && isLeaf){
		vector<int>::iterator iter;
		for(iter = path.begin();iter != path.end();iter++){
			cout << *iter << " ";
		}
	}		
	if(pRoot->m_pLeft != nullptr){FindPath(pRoot->m_pLeft, number, path, curNum);}	
	if(pRoot->m_pRight != nullptr){FindPath(pRoot->m_pRight, number, path, curNum);}	
	
	//The most important code line!!!
	path.pop_back();

}
