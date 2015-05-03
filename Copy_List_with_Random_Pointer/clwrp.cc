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
        unordered_map<RandomListNode*,int> ht1; 
        unordered_map<int, RandomListNode*> ht2; 

        RandomListNode *dummy = new RandomListNode(-1);
        RandomListNode *nd = head;
        RandomListNode *copy = dummy;

        int idx = 0;
        while(nd)
        {
            copy->next = new RandomListNode(nd->label); 
            ht1[nd] = idx;
            ht2[idx] = copy->next;

            nd = nd->next;
            copy = copy->next;
            idx ++;
        }

        nd = head;
        copy = dummy->next;
        while(nd)
        {
            if(nd->random)
                copy->random = ht2[ht1[nd->random]];  
            else 
                copy->random = NULL;
            nd = nd->next;
            copy = copy->next;
        }

        RandomListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};
