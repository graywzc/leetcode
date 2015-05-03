/**
 * Definition for binary tree
 */
#include <stdio.h>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:

    static bool getDepth(TreeNode* nd, int *depth)
    {
        if(nd == NULL)
        {
            *depth = 0;
            return true;
        }

        int d1,d2; 
        if(!getDepth(nd->left, &d1))
            return false;
        if(!getDepth(nd->right, &d2))
            return false;
        if(abs(d1-d2)>1)
            return false;
        *depth = max(d1,d2)+1;             

        return true;
    }

    static bool isBalanced(TreeNode *root) {
        int d;
        return getDepth(root, &d); 
    }
};

int main()
{
    TreeNode a(1);
    if(Solution::isBalanced(&a))
        printf("balanced\n");
    else
        printf("not balanced\n");
}
