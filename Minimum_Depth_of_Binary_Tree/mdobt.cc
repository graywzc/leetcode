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
    int minDepth(TreeNode *root) {
        if(root == NULL)        
        {
            return 0; 
        }
        else
        {
            if(root->left == NULL && root->right == NULL)
                return 1;
            else if(root->left == NULL)
                return 1+minDepth(root->right); 
            else if(root->right == NULL)
                return 1+minDepth(root->left); 
            else
                return 1+min(minDepth(root->left), minDepth(root->right));
        }
    }
};
