/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

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
    	ListNode* first = dummy, second = dummy;
    	for (int i = 0; i < n; i++)
    		second = second->next;

    	// add synchronously
    	while (second->next != NULL) //not the last
    	{
    		first = first->next;
    		second = second->next;
    	}
    	// delete
    	second->next = second->next->next;
    	return dummy->next;
    }
};