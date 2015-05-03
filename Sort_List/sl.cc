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
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *nd1 = head;           
        ListNode *nd2 = head->next;

        while(nd2 && nd2->next)
        {
            nd1 = nd1->next; 
            nd2 = nd2->next;
            nd2 = nd2->next;
        }

        nd2 = nd1->next; 
        nd1->next = NULL;
        nd1 = head;
        nd1 = sortList(nd1);
        nd2 = sortList(nd2);
        ListNode * dummy = new ListNode(-1);
        ListNode * nd = dummy;
        while(nd1 && nd2)
        {
            if(nd1->val < nd2->val) 
            {
                nd->next = nd1; 
                nd = nd1;
                nd1 = nd1->next;
            }
            else
            {
                nd->next = nd2; 
                nd = nd2;
                nd2 = nd2->next;
            }
        }

        if(nd1 == NULL) 
            nd->next = nd2;
        else
            nd->next = nd1;

        ListNode * res = dummy->next;
        delete dummy;
        return res;
    }
};

