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
    typedef struct{
    bool isValid;
    int max;
    int min;
    } Res;
    
    Res isValid(TreeNode *nd)
    {
        if(nd->left == NULL && nd->right == NULL) 
        {
            Res res; 
            res.isValid = true;
            res.max = nd->val;
            res.min = nd->val;
            return res;
        }
        else if (nd->right == NULL)
        {
            Res lres = isValid(nd->left); 
            Res res;
            res.isValid = lres.isValid && lres.max<nd->val;
            res.max = nd->val;
            res.min = lres.min;
            return res;
        }
        else if (nd->left == NULL)
        {
            Res rres = isValid(nd->right); 
            Res res;
            res.isValid = rres.isValid && rres.min>nd->val;
            res.max = rres.max;
            res.min = nd->val;
            return res;
        }
        else
        {
            Res lres = isValid(nd->left); 
            Res rres = isValid(nd->right); 
            Res res;
            res.isValid = lres.isValid && rres.isValid && lres.max<nd->val && rres.min>nd->val;
            res.max = rres.max;
            res.min = lres.min;
            return res;
        }
    }
    bool isValidBST(TreeNode *root) {
        if(root==NULL) 
            return true;
        Res res = isValid(root);
        return res.isValid;
    }
};
