/***
 * 比剑指Offer更优雅的方案
 *
 * ***/
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
}

ListNode* detectCycle(ListNode* head){
	ListNode *slow = head, *fast = head;
	while(slow != nullptr && fast != nullptr && fast->m_pNext != nullptr){
	slow = slow->m_pNext;
	fast = fast->m_pNext->m_pNext;
	if(fast == slow){
		//找到环中的节点的时候，将slow放到head出，重新开始跑，修改步长
		slow = head;
		while(slow != fast){
			slow = slow->m_pNext;
			fast = fast->m_pNext;
		}
		return slow;
	}
	}
	return nullptr;
	
}
