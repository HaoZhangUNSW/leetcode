ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	ListNode* pAhead = pListHead;
	ListNode* pBehind = nullptr;
	for(unsigned int i = 0;i < k - 1;i++){
		//corner case analysis
		if(pAhead->m_pNext != nullptr){
			pAhead = pAhead -> m_pNext;
		}else{
			return nullptr;
		}
	}
	pBehind = pListHead;
	while(pAhead->m_pNext != nullptr){
		pAhead = pAhead->m_pNext;
		pBehind=pBehind->m_pNext;
	}
	return pBehind;
}
