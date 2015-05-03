/**
 * Definition for binary tree
 */ 
#include <stdio.h>
#include <limits.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    
    static void dfsFindError(TreeNode *nd, TreeNode** prev, TreeNode** nd1, TreeNode** nd2)
    {
        if(nd->left) 
            dfsFindError(nd->left, prev, nd1, nd2);
        
        if(nd->val < (*prev)->val) 
        {
            if((*nd1) == NULL) 
                *nd1 = *prev;
            *nd2 = nd;
        }
        else
            *prev = nd;

        if(nd->right)
        {
            dfsFindError(nd->right, prev, nd1, nd2); 
        }
    }
    static void recoverTree(TreeNode *root) {
        TreeNode dummy(INT_MIN);
        TreeNode *nd1 = NULL;
        TreeNode *nd2 = NULL;
        TreeNode * pd = &dummy;

        dfsFindError(root, &pd, &nd1, &nd2);
        int temp = nd1->val;
        nd1->val = nd2->val;
        nd2->val = temp;
    }
};

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);

    Solution::recoverTree(root);

    delete root->left;
    delete root;
}
