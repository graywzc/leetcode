// recursive
//
/**
 * Definition for binary tree
 */
#include <stdio.h>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    static void postorderT(vector<int>& res, TreeNode* node)
    {
        if(node == NULL)
            return;
        postorderT(res, node->left);
        postorderT(res, node->right);
        res.push_back(node->val);
        return;
    }
    static vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;        
        postorderT(res, root);

        return res;
    }
};

int main()
{
    vector<int> res = Solution::postorderTraversal(NULL);
}
