class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k <= 1)	return head;
		ListNode* pStart(head), *pEnd(head), *prevEnd = new ListNode(-1), *temp;
		prevEnd->next = head;
		ListNode* newHead = prevEnd;
		int cnt = 0;
		while (pEnd != nullptr) {
			cnt = 0;
			while (cnt < k && pEnd != nullptr) {
				++cnt;
				pEnd = pEnd->next;
			}
			if (cnt != k)	break;
			temp = prevEnd;
			prevEnd = reverserPartOfList(pStart, pEnd);
			temp->next = pStart;
			pStart = prevEnd->next;
		}
		return newHead->next;
	}

	ListNode* reverserPartOfList(ListNode* &pStart, ListNode* &pEnd) {
		if (pStart == nullptr) return nullptr;
		ListNode* pNode = pStart->next, *temp = pStart, *newEnd = pStart;
		pStart->next = pEnd;
		while (pNode != nullptr && pNode != pEnd) {
			pStart = pNode->next;
			pNode->next = temp;
			temp = pNode;
			swap(pNode, pStart);
		}
		return newEnd;
	}
};