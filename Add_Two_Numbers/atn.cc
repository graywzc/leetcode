class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
            
        ListNode* res = new ListNode(0);
        ListNode* l3 = res;
        while (l1 || l2)
        {
            int temp = (l1?l1->val:0) + (l2?l2->val:0) + l3->val;
            if ((l1?l1->next:NULL) || (l2?l2->next:NULL) || temp>9)
            {
                l3->next = new ListNode(0);
                if (temp>9)
                    l3->next->val = temp/10;
            }
            l3->val = temp%10;
            l3 = l3?l3->next:NULL;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        
        return res;
    }
};
