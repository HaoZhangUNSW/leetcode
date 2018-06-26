struct BinaryTreeNode{
	int 		m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}; 

void Print(BinaryTreeNode* pTreeRoot){
	if(pTreeRoot == nullptr){return;}
	queue<BinaryTreeNode*> queNode;
	queNode.push(pTreeRoot);
	while(queNode.size()){
		BinaryTreeNode* pNode = queNode.front();
		queNode.pop();
		show();
		if(pNode->m_pLeft){queNode.push(pNode->m_pLeft);}
		if(pNode->m_pRight){queNode.push(pNode->m_pRight);}
	}

}
