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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *nd = head; 
        while(nd)
        {
            ListNode *nd1 = nd->next;  
            while(nd1 && nd1->val == nd->val)
                nd1 = nd1->next;

            nd->next = nd1;
            nd = nd1;
        }

        return head;
    }
};
