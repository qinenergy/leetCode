class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* pVHead = new ListNode(0);
        pVHead->next = head;
        ListNode* prev(pVHead), *node1(head), *node2(nullptr);
        while(node1){
            node2 = node1->next;
            while(node2 && node1->val == node2->val)
                node2 = node2->next;
            if(node1->next == node2){
                prev->next = node1;
                prev = prev->next;
                node1 = node2;
            }
            else{
                prev->next = node2;
                node1 = prev->next;
            }
        }
        head = pVHead->next;
        delete pVHead;
        return head;
    }
};