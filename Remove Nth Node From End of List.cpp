/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // add dummy nodes (for corner case: delete first nodes)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        //use two pointers, their gap is n
        ListNode* first = dummy;
        ListNode* second = dummy;
        for (int i = 0; i < n; i++)
            first = first->next;

        // add synchronously
        while (first->next != NULL) //not the last
        {
            first = first->next;
            second = second->next;
        }
        // delete
        second->next = second->next->next;
        return dummy->next;
    }
};