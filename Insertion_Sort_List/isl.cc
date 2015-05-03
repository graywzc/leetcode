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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(0);       
        dummy->next = head;

        ListNode *nd = dummy->next;
        while(nd->next)
        {
            ListNode *nd1 = dummy; 
            while(nd1!=nd && nd->next->val > nd1->next->val)
                nd1 = nd1->next;
            if(nd1 == nd)
            {
                nd = nd->next; 
            }
            else
            {
                ListNode* temp = nd->next; 
                nd->next = temp->next;
                temp->next = nd1->next;
                nd1->next = temp;
            }
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
