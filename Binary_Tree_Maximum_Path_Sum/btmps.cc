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
    
    void maxPathSum(TreeNode *nd, int &mps, int &mprs)
    {
        if(nd->left == NULL && nd->right == NULL)
        {
            mps = nd->val;
            mprs = nd->val;
        }
        else if(nd->left == NULL)
        {
            int rmps, rmprs;
            maxPathSum(nd->right, rmps, rmprs);
            mprs = rmprs>0?(rmprs+nd->val):nd->val;
            mps = max(rmps, mprs);
        }
        else if(nd->right == NULL)
        {
            int lmps, lmprs; 
            maxPathSum(nd->left, lmps, lmprs);
            mprs = lmprs>0?(lmprs+nd->val):nd->val;
            mps = max(lmps, mprs);
        }
        else
        {
            int lmps, lmprs, rmps, rmprs; 
            maxPathSum(nd->left, lmps, lmprs);
            maxPathSum(nd->right, rmps, rmprs);
            mprs = max(nd->val, nd->val+lmprs);
            mprs = max(mprs, nd->val+rmprs);
            mps = max(lmps, rmps);
            mps = max(mps, nd->val + (lmprs>0?lmprs:0) + (rmprs>0?rmprs:0));
        }
    }
    
    int maxPathSum(TreeNode *root) {
        if(root == NULL)
            return 0;
        int mps, mprs;
        maxPathSum(root, mps, mprs);    
        return mps;
    }
};
