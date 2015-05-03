/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* stb(ListNode *head, ListNode *stop)
    {
        if(head->next == stop)  
        {
            TreeNode *nd = new TreeNode(head->val); 
            return nd;
        }
        else if(head->next->next == stop)
        {
            TreeNode *nd = new TreeNode(head->next->val); 
            nd->left = new TreeNode(head->val);
            return nd;
        }
        else
        {
            ListNode *nd1 = head; 
            ListNode *nd2 = head;
            while(nd2->next!=stop)
            {
                nd2 = nd2->next; 
                nd1 = nd1->next;
                if(nd2->next!=stop)
                    nd2 = nd2->next;
                else
                    break;
            }

            TreeNode *nd = new TreeNode(nd1->val);  
            nd->left = stb(head,nd1);
            nd->right = stb(nd1->next, stop);

            return nd;
        }

    }

    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        return stb(head, NULL);
    }
};
