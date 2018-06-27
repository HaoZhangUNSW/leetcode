void PrintListFromTail(ListNode* pHead){
	stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while(pNode != nullptr){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while(!nodes.empty()){
		pNode = nodes.top();
		print();
		nodes.pop();
	}
}

/***
 * Recursive Method
 *
 * ***/

void PrintListFromTail_Recur(ListNode* pHead){
	if(pHead != nullptr){
		if(pHead->m_pNext != nullptr){
			PrintListFromTail_Recur(pHead->m_pNext);
		}
	}
	print(pHead->m_pNext);
}
