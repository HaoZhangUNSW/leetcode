struct BinaryTreeNode{
	double m_dbValue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
};

bool Equal(double num1, double num2){
	if( (num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)){
		return true;
	}
	else{
		return false;
	}
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
	if(pRoot2 == nullptr){return true;}
	if(pRoot1 == nullptr){return false;}
	if(!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue)){return false;}
	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
	       DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

