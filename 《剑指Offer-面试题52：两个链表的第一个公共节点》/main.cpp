#include <iostream>
using namespace std;

struct ListNode{
	int 		m_nValue;
	struct ListNode* m_pNext;
};

ListNode* getFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
	if(pHead1 == nullptr || pHead2 == nullptr){return nullptr;}
	
	ListNode* pCur1 = pHead1;
	int lenOfHead1 = 0;
	while(pCur1 != nullptr){//TODO}
	//while(pCur1->m_pNext != nullptr){lenOfHead1++;pCur1 = pCur1->m_pNext;}
	ListNode* pCur2 = pHead2;
	int lenOfHead2 = 0;
	while(pCur2 != nullptr){//TODO}
	//while(pCur2->m_pNext != nullptr){lenOfHead2++;pCur2 = pCur2->m_pNext;}
	
	pCur1 = pHead1;
	pCur2 = pHead2;

	int diff = lenOfHead1 - lenOfHead2;
	diff = lenOfHead1 > lenOfHead2 ? diff : -diff;
	//Modify Code
	if(lenOfHead2 > lenOfHead1){
		pCur1 = pHead2;
		pCur2 = pHead1;
		diff = -diff;
	
	}	
	if(lenOfHead1 > lenOfHead2){
		while(diff > 0){
			pCur1  = pCur1->p_mNext;
			diff--;
		}
		while(*pCur1 != *pCur2){
			pCur1 = pCur1->p_mNext;
			pCur2 = pCur2->p_mNext;
		}
		return pCur1;//pCur2
	}
	else if(lenOfHead1 < lenOfHead2){
		while(diff > 0){
			pCur2  = pCur2->p_mNext;
			diff--;
		}
		//Condition to Compare
		while( (pCur1 != nullptr)  && (pCur2 != nullptr) && (pCur1 != pCur2))
		//while(*pCur1 != *pCur2){
			pCur1 = pCur1->p_mNext;
			pCur2 = pCur2->p_mNext;
		}
		return pCur1;//pCur2
	}
	else{
		while(*pCur1 != *pCur2){
			pCur1 = pCur1->p_mNext;
			pCur2 = pCur2->p_mNext;
		}
		return pCur1;//pCur2
	}
	return nullptr;
}

int main(){
	return 0;
}
