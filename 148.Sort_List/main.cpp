
/***
 * 单链表排序
 * https://www.cnblogs.com/zywu/p/5771306.html
 *
 * ***/

struct ListNode{
	int m_nValue;
	struct ListNode* m_pNext;
};

ListNode* sortList(ListNode* head){
	if(head == nullptr || head->m_pNext == nullptr){return head;}
	
	// get the mid point of the link list.
	ListNode* prev = nullptr;
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast && fast->m_PNext){
		prev = slow;
		slow = slow->m_pNext;
		fast = fast->m_pNext->m_PNext;
	}
	ListNode* mid = slow;
	
	prev->next = nullptr;
	ListNode* left = sortList(head);
	ListNode* right = sortList(mid);
	return mergeList(left, right);
}	

/***
 * 递归方法
 *
 * ***/

ListNode* mergeList(ListNode* left, ListNode* right){
	if(left == nullptr){return right;}
	if(right == nullptr){return left;}
	ListNode* head = nullptr;
	if(left->m_nValue <= right->m_nValue){
		head = left;
		head->m_pNext = mergeList(left->m_pNext, right);
	}else{
		head = right;
		head->m_pNext = mergeList(left, right->m_pNext);
	}
	return head;
}


/***
 * 非递归方法
 *
 * ***/
ListNode* mergeList(ListNode* left, ListNode* right){
	//哨兵，保存头指针，cur指针在不断变化
	ListNode* guard = new ListNode(0);
	ListNode* cur = guard;
	while(left && right){
		if(left->m_nValue <= right->m_nValue){
			cur->m_pNext = left;
			left = left->m_pNext;
		}else{
			cur->m_pNext = right;
			right = right->m_pNext;
		}
		cur = cur->m_pNext;
	}
	if(left){cur->m_pNext=left;}
	if(right){cur->m_pNext=right;}
	return guard->m_pNext;
}

