/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || m >= n)    return head;
        ListNode* p1(nullptr), *p2(head), *p3(nullptr);
        int cnt = 0;
        while(cnt < m - 1){
            ++cnt;
            p1 = p2;
            p2 = p2->next;
        }
        ListNode* before_start = p1, *start = p2;
        p3 = p2->next;
        cnt = n - m;
        while(cnt >= 0){
            --cnt;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 != nullptr ? p3 = p3->next : p3 = nullptr;
        }
        if(before_start != nullptr) before_start->next = p1;
        start->next = p2;
        if(before_start == nullptr)
            return p1;
        else return head;
    }
};
