/***
 *
 * slow and fast pointers do not need to start from the head.
 * the most important thing is having two pointers with diff speed.
 *
 * ***/
ListNode* MeetingNode(ListNode* pHead){
	if(pHead == nullptr){return nullptr;}
	ListNode* pSlow = pHead->m_pNext;
	if(pSlow == nullptr){return nullptr;}
	ListNode* pFast = pSlow->m_pNext;
	while(pFast != nullptr && pSlow != nullptr){
		if(pFast == pSlow){return pFast;}
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if(pFast != nullptr){pFast = pFast->m_pNext;}		
	
	}
	return nullptr;
}

/***
 *
 * the K-th node to tail of listnode. classical method.
 *
 * ***/
ListNode* EntryNodeOfLoop(ListNode* pHead){
	ListNode* meetingNode = MeetingNode(pHead);
	if(meetingNode == nullptr){return nullptr;}
	//get number of nodes of circle
	int number = 0;
	ListNode* pNodeTemp = meetingNode;
	while(pNodeTemp->m_pNext != meetingNode){
		pNodeTemp = pNodeTemp->m_pNext;
		number++;
	}
	pNodeTemp = pHead;
	for(int i = 0;i < number;i++){
		pNodeTemp = pNodeTemp->m_pNext;
	}
	ListNode* pNode = pHead;
	while(pNode != pNodeTemp){
		pNode = pNode->m_pNext;
		pNodeTemp = pNodeTemp->m_pNext;	
	}		
	return pNode;
}
