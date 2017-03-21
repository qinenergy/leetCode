class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode* pSmall = new ListNode(-1);
    	ListNode* pLarge = new ListNode(-1);
    	ListNode* pSHead(pSmall), *pLHead(pLarge), *pNode(head);
    	if(!head)	return head;
    	while(pNode != nullptr){
    		if(pNode->val < x){
    			pSmall->next = pNode;
    			pNode = pNode->next;
    			pSmall = pSmall->next;
    			pSmall->next = nullptr;
    		}
    		else{
    			pLarge->next = pNode;
    			pNode = pNode->next;
    			pLarge = pLarge->next;
    			pLarge->next = nullptr;
    		}
    	}
    	pSmall->next = pLHead->next;
    	head = pSHead->next;
    	delete pSHead;
    	delete pLHead;
    	return head;
    }
};