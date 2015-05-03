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
    ListNode *reverseBetween(ListNode *head, int m, int n) {

        if(NULL == head) return NULL;
        ListNode *dummy = new ListNode(0);        
        dummy->next = head;
        
        ListNode* nd = dummy;
        while(m>1)
        {
            nd = nd->next;
            m--;
            n--;
        }    

        TreeNode* nd1 = nd->next;
        while(n>1)
        {
            TreeNode * temp = nd1->next; 
            nd1->next = temp->next;
            temp->next = nd->next;
            nd->next = temp;
            n--;
        }

        TreeNode* res = dummy->next;
        delete dummy;
        return res;

    }
};
