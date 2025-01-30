class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;  

        ListNode* node = head;
        ListNode* prev = nullptr;
        head = node->next;  

        while (node && node->next) {
            ListNode* node2 = node->next;
            node->next = node2->next;
            node2->next = node;
            if (prev) prev->next = node2;
            prev = node;
            node = node->next;
        }
        return head;
    }
};
