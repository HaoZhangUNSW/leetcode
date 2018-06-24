struct ListNode{
	int m_nValue;
	struct ListNode* m_pNext;
};
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
	if(!pListHead || !pToBeDeleted){return;}
	//body node
	if(pToBeDeleted->m_pNext != nullptr){
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		deleted pNext;
		pNext = nullptr;
	}else if(*pListNode == pToBeDeleted){//head node
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListNode = nullptr;
	}
	//tail node
	else{
		ListNode* pNode = *pListNext;
		while(pNode->m_pNext != pToBeDeleted){
			pNode = pNode->m_pNext;			
		}	
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}
