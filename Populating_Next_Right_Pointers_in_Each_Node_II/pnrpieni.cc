/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(NULL == root)    
            return;
        
        TreeLinkNode* nd;
        TreeLinkNode* next_nd = NULL;
        TreeLinkNode* start_nd = NULL;
        TreeLinkNode* child_next_nd = NULL;
        nd = root;
        while(1)
        {
            next_nd = nd->next;
            while(next_nd && next_nd->left==NULL && next_nd->right==NULL) 
            {
                next_nd = next_nd->next;
            }
            if(next_nd)
                child_next_nd = next_nd->left?next_nd->left:next_nd->right;

            if(start_nd == NULL)
            {
                if(nd->left) 
                    start_nd = nd->left;
                else if(nd->right)
                    start_nd = nd->right;
            }
            
            if(nd->left)  
            {
                if(nd->right)
                {
                    nd->left->next = nd->right; 
                    if(next_nd)
                        nd->right->next = child_next_nd;
                }
                else
                {
                    if(next_nd) 
                        nd->left->next = child_next_nd;
                }
            }
            else
            {
                if(nd->right)
                    if(next_nd)
                        nd->right->next = child_next_nd;
            }

            if(next_nd == NULL && start_nd == NULL)
                break;
            else if(next_nd)
                nd = next_nd;
            else
            {
                nd = start_nd;
                start_nd = NULL;
            }
        }
        
    }
};
