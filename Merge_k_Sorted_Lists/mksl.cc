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

    ListNode *merge2Lists(ListNode * l1, ListNode * l2)
    {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else
        {
            ListNode* dummy = new ListNode(0);
            ListNode* n = dummy; 

            while(l1 && l2)
            {
                if(l1->val < l2->val)     
                {
                    n->next = l1; 
                    n = l1;
                    l1 = l1->next;
                }
                else
                {
                    n->next = l2;
                    n = l2;
                    l2 = l2->next;
                }
            }

            if(l1 == NULL)
               n->next = l2;
            else
               n->next = l1;

            n = dummy->next;
            delete dummy;

            return n;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();

        if(n == 0)
            return NULL;
        if(n == 1)
            return lists[0];

        int k = n;
        while(k > 1)
        {
            int i;
            for(i = 0; i < k/2; i++) 
            {
                lists[i] = merge2Lists(lists[2*i], lists[2*i+1]);            
            }
            if(k%2)
            {
                lists[i] = lists[k-1];
                k = i+1;
            }
            else
                k = i;
        }

        return lists[0];
    }
};
