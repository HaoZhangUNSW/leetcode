struct BinaryTreeNode{
	int m_nValue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}

int TreeDepth(BinaryTreeNode* pRoot){
	if(pRoot == nullptr){return 0;}
	int nLeft = TreeDepth(pRoot->m_pLeft);
	int nRight = TreeDepth(pRoot->m_pRight);	
	return (nLeft > nRight) ? nLeft + 1 : nRight + 1;
}
