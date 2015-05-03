/**
 * Definition for binary tree
 */
#include <stdio.h>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    static bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;

        TreeNode *left = root->left;        
        TreeNode *right = root->right;
        stack<TreeNode*> stl;
        stack<TreeNode*> str;

        while(1)
        {
            while(left!=NULL)
            {
                if(right==NULL) return false;
                stl.push(left); 
                left = left->left;
                str.push(right);
                right = right->right;
            }
            
            if(right!=NULL) return false;
            if(stl.size() == 0) return true;
            left = stl.top();
            stl.pop();
            right = str.top();
            str.pop();
            if(left->val != right->val) return false;
            left = left->right;
            right = right->left;
        }

    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    if(Solution::isSymmetric(root))
        printf("yes\n");
    else
        printf("no\n");


    delete root;
    delete root->left;
}
