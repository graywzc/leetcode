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

    bool hps(TreeNode *root, int sum)
    {
        if(root->left && hps(root->left, sum - root->val))
            return true;
        if(root->right && hps(root->right, sum - root->val))
            return true;
        if(root->left == NULL && root->right == NULL)
            return (sum==root->val);
        return false;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        return hps(root, sum);
    }
};
