/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // Create a dummy head node to simplify the process of returning the new head.
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy; // Pointer to the node before the pair being swapped

    // We continue as long as there are at least two nodes remaining to be swapped
    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* node1 = prev->next;
        struct ListNode* node2 = prev->next->next;

        // Perform the swap:
        prev->next = node2;
        node1->next = node2->next;
        node2->next = node1;

        // Move the 'prev' pointer forward by two positions to the next pair's preceding node
        prev = node1;
    }

    // The new head of the list is attached to the dummy node's next pointer
    return dummy.next;
}
