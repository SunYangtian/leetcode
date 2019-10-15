// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

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
    ListNode* reverseList(ListNode* l)
    {
        ListNode* tmp;
        ListNode* new_node = NULL;
        while (l)
        {
            tmp = l;
            l = l->next;
            tmp->next = new_node;
            new_node = tmp;
        }
        return new_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add1, add2, tmp, carry = 0;
        ListNode* res = NULL;
        // add digits by digits and calculate carry
        while (l1 || l2 || carry) // loop as long as one has value
        {
            if (l1) add1 = l1->val; else add1 = 0;
            if (l2) add2 = l2->val; else add2 = 0;
            tmp = (add1 + add2 + carry) % 10;
            carry = (add1 + add2 + carry) / 10;

            if(l1) l1 = l1->next; 
            if(l2) l2 = l2->next;

            // store result
            ListNode* res_tmp = new ListNode(tmp);
            res_tmp->next = res;
            res = res_tmp;   
        }
        res = reverseList(res);
        return res;
    }
};