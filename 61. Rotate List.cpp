class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* node = head, *newHead = nullptr, *oldEnd;
        while(node != nullptr){
        	if(node->next == nullptr)
        		oldEnd = node;
        	node = node->next;
        	++len;
        }
        k = k % len;
        if(k == 0)	return head;
        node = head;
        for(int i = 0; i < len - k; ++i){
        	if(i == len - k - 1){
        		newHead = node->next;
        		node->next = nullptr;
        		oldEnd->next = head;
        		return newHead;
        	}
        	node = node->next;
        }
    }
};