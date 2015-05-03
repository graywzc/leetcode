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
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) 
            return;
        
        ListNode *n1 = head;
        ListNode *n2 = head;
        while(n2->next && n2->next->next)
        {
            n1 = n1->next; 
            n2 = n2->next->next;
        }

        if(n2->next)
        {
            n1 = n1->next;
            n2 = n2->next;
        }

        ListNode *n3 = n1->next;
        n1->next = NULL;
        n1 = n3->next;
        n3->next = NULL;
        while(n1)
        {
            n2 = n1->next;
            n1->next = n3; 
            n3 = n1;
            n1 = n2;
        }
        
        n1 = head;
        while(n3)
        {
            n2 = n3->next;
            n3->next = n1->next;
            n1->next = n3;
            n3 = n2;
            n1 = n1->next->next;
        }

        return;
        
    }

};
