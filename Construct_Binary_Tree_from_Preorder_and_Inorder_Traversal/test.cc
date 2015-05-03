/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
# include <stdio.h>
# include <stdlib.h>
# include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    static TreeNode *buildTree(const vector<int> &preorder, int startp, int endp, const vector<int> &inorder, int starti, int endi)
    {
        if(startp > endp) 
            return NULL;
        else
        {
            TreeNode *nd = new TreeNode(preorder[startp]);
            int i = starti;
            while(i <= endi)
            {
                if(inorder[i] == preorder[startp])
                    break;
                i++; 
            }

            nd->left = buildTree(preorder, startp+1, startp+i-starti, inorder, starti, i-1);
            nd->right = buildTree(preorder, startp+i-starti+1, endp, inorder, i+1, endi);

            return nd;
        }
    }
    static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

void print_tree(TreeNode *root)
{
    if(root != NULL)
    {
        print_tree(root->left);
        print_tree(root->right);
        printf("%d ", root->val);
    }
}

int main()
{
    int i[] = {3,1,4,0,5,2,6};
    int p[] = {0,1,3,4,2,5,6};
    vector<int> porder(7);
    porder.assign(p,p+7);
    vector<int> iorder(7);
    iorder.assign(i,i+7);

    TreeNode *root = Solution::buildTree(porder,iorder); 
    print_tree(root);
    
}
