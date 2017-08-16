class Solution2 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail){
        if(head == tail)    return nullptr;
        ListNode* slow = head, *fast = head;
        while(fast != tail){
            fast = fast->next;
            if(fast == tail) break;
            fast = fast->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);
        return root;
    }
};
