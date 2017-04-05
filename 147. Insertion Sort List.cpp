class Solution2 {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pVHead(0), *pi(head->next), *pj(nullptr), *pNext(nullptr), *pPrev(nullptr);
        pVHead = new ListNode(0);
        pVHead->next = head;
        pPrev = head;
        while(pi){
            pNext = pi->next;
            pj = pVHead; 
            while(pj != pPrev && pj->next->val < pi->val)   pj = pj->next;
            if(pj != pPrev){
                auto tmp = pj->next;
                pPrev->next = pNext;
                pi->next = tmp;
                pj->next = pi;
                pi = pPrev->next;
            }
            else{
                pPrev = pi;
                pi = pi->next;
            }
        }
        head = pVHead->next;
        delete pVHead;
        return head;
    }
};