/**
 * Definition for binary tree
 */
#include <vector>
#include <stdio.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    
    static int recurPathSum(vector<vector<int> > &res, TreeNode *nd, int lvl, int sum)
    {
        if(NULL == nd->left && NULL == nd->right) 
        {
            if(sum == nd->val) 
            {
                vector<int>  temp(lvl); 
                temp[lvl-1] = nd->val;
                res.push_back(temp);
            }
            return 1;
        }
        int n = 0, i =res.size();
        if(NULL != nd->left)
            n += recurPathSum(res, nd->left, lvl+1, sum - nd->val); 
        if(NULL != nd->right)
            n += recurPathSum(res, nd->right, lvl+1, sum - nd->val);
        
        while(i < res.size())
        {
            res[i++][lvl-1] = nd->val; 
        }

        return n;

    }
    
    static vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(root == NULL)
            return res; 

        recurPathSum(res, root, 1, sum);  

        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    TreeNode *nd = root->left;
    nd->left = new TreeNode(11);
    nd = nd->left;
    nd->left = new TreeNode(7);
    nd->right = new TreeNode(2);
    nd = root->right;
    nd->left = new TreeNode(13);
    nd->right = new TreeNode(4);
    nd = nd->right;
    nd->left = new TreeNode(5);
    nd->right = new TreeNode(1);

    vector<vector<int> > res = Solution::pathSum(root, 22);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++) 
            printf("%d ", res[i][j]);

        printf("\n");
    }
}
