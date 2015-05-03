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
        ListNode *dummy = new ListNode(-1);        
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = dummy->next;
        ListNode *post;
        while(cur)
        {
            post = cur->next; 
            while(post!=NULL && post->val == cur->val)
                post = post->next;
            if(post == cur->next)
            {
                pre = cur; 
                cur = post;
            }
            else
            {
                while(cur!=post)
                {
                    ListNode *temp = cur; 
                    cur = cur->next;
                    delete temp;
                }
                pre->next = post;
            }
        }

        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};
