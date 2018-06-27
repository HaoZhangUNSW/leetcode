/***
 * 链表不要断：断裂前保存指向元素的指针
 *
 * ***/
ListNode* reverse(ListNode* pHead){
	ListNode* pNewHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;
	while(pNode != nullptr){
		ListNode* pNext = pNode->m_pNext;		
		if(pNext == nullptr){pNewHead = pNode;}	
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pNewHead;
}
