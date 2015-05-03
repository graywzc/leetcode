/**
 * Definition for singly-linked list.
 */ 
#include <stdio.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    static ListNode *reverseKGroup(ListNode *head, int k) {
        if(k <= 1)        
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int n;
        ListNode *nd1 = dummy;
        ListNode *nd2 = dummy;
        ListNode *nd3;
        ListNode *nd4;
        while(1)
        {
            n = k; 
            while(n>0 && nd2->next)
            {
                n--; 
                nd2 = nd2->next;
            }
            if(n>0)
                break;

            nd4 = nd1->next;
            nd3 = nd4->next;
            while(nd4!= nd2)
            {
                ListNode* temp = nd3->next;  
                nd3->next = nd4;
                nd4 = nd3;
                nd3 = temp;
            }
            nd4 = nd1->next;
            nd4->next = nd3; 
            nd1->next = nd2;
            nd1 = nd4; 
            nd2 = nd4;
        }

        ListNode * res = dummy->next;
        delete dummy;
        return res;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);

    ListNode *res = Solution::reverseKGroup(head, 2);
}
