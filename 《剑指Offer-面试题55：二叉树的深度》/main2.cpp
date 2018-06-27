/***
 * 判断一棵树是否是平衡二叉树
 *
 * ***/

bool IsBalanced(BinaryTreeNode* pRoot){
	if(pRoot == nullptr){return true;}
	
	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);
	int diff = left - right;
	
	if(diff > 1 || diff < -1){return false;}
	return IsBalanced(pRoot-m_pLeft) && IsBalanced(pRoot->m_pRight);
}
