/**
 * Definition for singly-linked list.
 */ 
#include <stdio.h>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    static ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *boundary = dummy;
        ListNode *nd = dummy;
        while( nd->next)
        {
            if(nd->next->val < x) 
            {
                if(boundary != nd)
                {
                    ListNode* temp = nd->next;
                    nd->next = temp->next;
                    temp->next = boundary->next;
                    boundary->next = temp;
                    boundary = boundary->next;  
                }
                else
                {
                    nd = nd->next;
                    boundary = boundary->next;
                }
            }
            else
            {
                nd = nd->next; 
            }
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
        
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    head ->next = new ListNode(1);
    head->next->next = new ListNode(2);

    ListNode *res = Solution::partition(head, 3);

    while(res!=NULL)
    {
        printf("%d ", res->val); 
        res = res->next;
    }
    printf("\n");
}
