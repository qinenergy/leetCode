class Solution2 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        // 1. copy nodes
        auto node = head;
        while(node != nullptr){
            auto new_node = new RandomListNode(node->label);
            new_node->next = node->next;
            node->next = new_node;
            node = new_node->next;
        }
        // 2. set the random pointer in copied node
        node = head;
        while(node != nullptr){
            auto new_node = node->next;
            new_node->random = (node->random == nullptr) ? nullptr : node->random->next;
            node = new_node->next;
        }
        // 3. split
        node = head;
        auto new_head = node->next, new_node = new_head;
        while(node != nullptr){
            node->next = new_node->next;
            new_node->next = (new_node->next == nullptr) ? nullptr : new_node->next->next;
            node = node->next;
            new_node = new_node->next;
        }
        return new_head;
    }
};
