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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next==NULL)
            return head;

        int n = 1;
        ListNode *nd = head;
        while(nd->next)        
        {
            nd = nd->next; 
            n++;
        }
        nd->next = head;

        k = n - k%n;

        while(k>0)
        {
            nd = nd->next;
            k--; 
        }

        ListNode* res = nd->next;
        nd->next = NULL; 
        return res;
        
    }
};
