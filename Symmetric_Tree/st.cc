// recursvie method
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
    bool isSymmetrical(TreeNode *left, TreeNode *right)
    {
        if(left == NULL && right ==  NULL)  
        {
            return true;
        }
        else if(left&&right)
        {
            return (left->val == right->val)&&(isSymmetrical(left->left,right->right))&&(isSymmetrical(left->right,right->left));  
        }
        else
            return false;
    }

    bool isSymmetric(TreeNode *root) {
        if(root == NULL) 
            return true;
        else
            return isSymmetrical(root->left, root->right);
    }
};
