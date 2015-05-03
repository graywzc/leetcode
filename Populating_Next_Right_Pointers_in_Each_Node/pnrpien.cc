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
        if(root!= NULL )
        {   if( root->left!= NULL)
            {
                root->left->next = root->right;       
                TreeLinkNode *nd1 = root->left;
                TreeLinkNode *nd2 = root->right;

                while(nd1->right != NULL)
                {
                    nd1 = nd1->right; 
                    nd2 = nd2->left;
                    nd1->next = nd2;
                }
            }
            connect(root->left);
            connect(root->right);
        }

    }
};
