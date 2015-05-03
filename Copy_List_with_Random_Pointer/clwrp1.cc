// better solution
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(head == NULL)
            return NULL;

        RandomListNode * nd = head;                
        RandomListNode *copy;
        while(nd)
        {
            copy = new RandomListNode(nd->label);     
            copy->next = nd->next;
            nd->next = copy;
            nd = copy->next;
        }

        nd = head;
        while(nd)
        {
            nd->next->random = (nd->random)?(nd->random->next):NULL; 
            nd = nd->next->next;
        }

        nd = head; 
        RandomListNode *res = nd->next;
        while(nd)
        {
            copy = nd->next;
            nd->next = copy->next; 
            copy->next = copy->next?copy->next->next:NULL;
            nd = nd->next;
        }

        return res;
    }
};
