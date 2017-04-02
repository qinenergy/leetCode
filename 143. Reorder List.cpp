class Solution2 {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;       
        int len = 0, mid;
        ListNode* node = head, *prev, *next;
        while(node != nullptr){
            ++len;
            st.push(node);
            node = node->next;
        }
        if(len <= 2)    return;
        prev = head;
        mid = (len - 1) >> 1;
        for(int i = 0; i < mid; ++i){
            node = prev->next;
            next = st.top();
            st.pop();
            prev->next = next;
            next->next = node;
            prev = node->next;
            if(prev == next){
                node->next = nullptr;
                break;
            }
        }
        if(node->next) node->next->next = nullptr;
    }
};