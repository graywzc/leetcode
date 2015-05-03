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
    ListNode *swapPairs(ListNode *head) {
        if(head != NULL && head->next != NULL)        
        {
            head->next->next = swapPairs(head->next->next);
            ListNode* newhead = head->next;
            head->next = newhead->next;
            newhead->next = head;
            return newhead;
        }
        else
            return head;
    }
};
