typedef struct ListNode{
	int data;
	struct ListNode* next;
}ListNode;

ListNode* ReverseList(ListNode* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	ListNode* p = head;
	ListNode* newHead;
	stack<ListNode*> _stack;
	
	while(p->next){
		_stack.push(p);
		p = p->next;
	}
	newHead = p;
	while(!_stack.empty()){
		p->next = _stack.top();
		p = p->next;
		_stack.pop();
	}
	p->next = NULL;
	return newHead;
}
