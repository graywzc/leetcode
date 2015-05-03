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
    
    TreeNode* fla(TreeNode *nd)
    {
        if(nd->left == NULL && nd->right == NULL) 
        {
            return nd; 
        }
        else if(nd->left == NULL)
        {
            return fla(nd->right); 
        }
        else if(nd->right == NULL)
        {
            nd->right = nd->left; 
            nd->left = NULL;
            return fla(nd->right);
        }
        else
        {
            TreeNode* temp = nd->right; 
            TreeNode* temp1 = fla(nd->left);
            nd->right = nd->left;
            nd->left = NULL;
            temp1->right = temp;
            return fla(temp);
        }
    }
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        fla(root); 
    }
};
