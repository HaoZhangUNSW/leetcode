#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution{
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
			if(l1 == nullptr){ return l2;}
			if(l2 == nullptr){ return l1;}	
			// classic paradigm
			ListNode dummy(-1);
			ListNode* p = &dummy;
			for(; l1 != nullptr && l2 != nullptr;p = p ->next){
				if(l1->val > l2->val){
					p->next = l2;
					l2 = l2->next;
				}else{
					p->next = l1;
					l1 = l1->next;
				}
			}
			p->next = l1 != nullptr? l1 : l2;
			return dummy.next;
		}
};
void createList(ListNode* &L, int* ary, int size){
	// C++ will not check the length of array
	ListNode* p = nullptr;
	for(int i = 0;i < size;i++){
		ListNode* tmp = new ListNode(ary[i]);
		if(L == nullptr){
			L = tmp;
			p = tmp;
		}else{
			p->next = tmp;
			p = tmp;
		}
	}
}
void deleteDup(ListNode* &L){

	//两只猴子荡秋千，一只追另一只
	
	if(L == nullptr){return;}
	ListNode* p = L;
	ListNode* q =  nullptr;
	while(p){
		q = p;
		while(q->next){
			if(q->next->val == p->val){
				q->next = q->next->next;
			}else{
				q = q->next;
			}
		}
		p = p->next;
	}
}

ListNode* deleteDuplicates(ListNode* head){
	
	//如果链表中原来有0个或者1个元素，不会有重复，直接返回
	if(!head || !head->next){return head;}		
	
	//防止由于从链表第一个节点开始就有重复，导致链表头部被修改
	ListNode* dummy = new ListNode(INT_MIN);
	dummy->next = head;
	
	ListNode* prev = dummy;
	while(prev->next){
		ListNode* cur = prev->next;
		while(cur->next && cur->next->val == cur->val){cur = cur->next;}
		if(cur != prev->next){prev->next = cur->next;}
		else{prev = prev->next;}
	
	}
	return dummy->next;
}

ListNode* reverse(ListNode* L){
	// p是L的跟屁虫，L从头到尾遍历一遍OK
	ListNode* p = nullptr;
	while(L){
		ListNode* q = L->next;
		L->next = p;
		p = L;
		L = q;
	}
	return p;
}
void moveNode(ListNode** destRef, ListNode** sourceRef){
	//拼接destRef的所有元素和sourceRef的第一个元素
	ListNode* newNode = *sourceRef;
	*sourceRef = newNode->next;
	newNode->next = *destRef;
	*destRef = newNode;
}

//单链表的顺序插入
//0.直接插入法(教科书)
//1.傀儡节点法
//2.引用法

void sortedInsert0(ListNode** headRef, ListNode* newNode){
	if(*headRef == nullptr || (*headRef)->val >= newNode->val){
		newNode->next = *headRef;
		*headRef = newNode;
	}else{
		ListNode* cur = *headRef;
		while(cur->next != nullptr && cur->next->val < newNode->val)
			cur = cur->next;
		newNode->next = cur->next;
		cur->next = newNode;
		
	}
}
void sortedInsert1(ListNode** headRef, ListNode* newNode){
	
	//可以利用成员函数，有不同的表达方式
	ListNode dummy(0), *tail = &dummy;
	dummy.next = *headRef;
	
	while(tail -> next != nullptr && tail->next->val < newNode->val)
		tail = tail->next;
	newNode->next = tail->next;
	tail->next = newNode;
	*headRef = dummy.next;	

}

void sortedInsert2(ListNode** headRef, ListNode* newNode){
	ListNode** curRef = headRef;
	while(*curRef != nullptr && (*curRef)->val < newNode->val)
		curRef = &((*curRef)->next);
	newNode->next = *curRef;
	*curRef = newNode;	
}

//链表排序(基于顺序插入实现)
void insertSort(ListNode** headRef){
	//TODO
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
	ListNode* curA = headA;
	ListNode* curB = headB;
	while(curA != curB){
		curA = curA? curA->next : headB;
		curB = curB? curB->next : headA;
	}	
	return curA;
}

bool isParlindrome(ListNode* head){
	//链表为空或者只有一个元素
	if(head == NULL || head->next == NULL){return true;}
	//链表元素个数>=2
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	slow->next = reverse(slow->next);
	slow = slow->next;
	while(slow != NULL){
		if(head->val != slow->val){return false;}
		head = head->next;
		slow = slow->next;
	}
	return true;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
	if (!head){return nullptr;}
	//class member
	ListNode new_head(-1);
	new_head.next = head;

	ListNode* slow = &new_head, *fast = &new_head;
	for(int i = 0;i < n;i++){fast = fast->next;}
	while(fast->next){
		fast = fast->next;
		slow = slow->next;	
	}
	//使用指针显式删除
	ListNode* to_be_deleted = slow->next;
	slow->next = slow->next->next;
	delete to_be_deleted;
	return new_head.next;
}

//ListNode* swapPairs(ListNode* head){
//	//TODO	
//}

int main(){
	
	int _l2[] = {1,2,3,3,4,4,5};
	ListNode* l2 = nullptr;
	createList(l2, _l2, sizeof(_l2)/sizeof(_l2[0]));
	ListNode* p = nullptr;
	l2 = deleteDuplicates(l2);
	p = l2;
	while(p){
		cout << p -> val << " ";
		p = p ->next;
	}
	return 0;
}
