class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode node(0);
   		ListNode* p1 = l1;
   		ListNode* p2 = l2;
   		ListNode* parent =&node;
   		int carry = 0;
   		while (p1 || p2 || carry) {
   		    int d1 = p1 ? p1->val : 0;
   		    int d2 = p2 ? p2->val : 0;
   		    if (p1) p1 = p1->next;
   		    if (p2) p2 = p2->next;
   		    carry += d1 + d2;
   		    ListNode* node = new ListNode(carry % 10);
   		    parent->next = node;
   		    parent = node;
   		    carry /= 10;
   		}
	    return node.next;
	}
};