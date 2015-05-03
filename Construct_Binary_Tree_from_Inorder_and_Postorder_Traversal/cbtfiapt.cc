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

    static TreeNode *buildTree(vector<int> &inorder, int starti, int endi, vector<int> &postorder, int startp, int endp)
    {
        if(starti > endi)
            return NULL;
        if(starti == endi)
        {
            TreeNode* parent = new TreeNode(inorder[starti]);  
            return parent; 
        }
        else
        {
            int pv = postorder[endp];
            TreeNode* parent = new TreeNode(pv); 
            int idx = starti;
            while(inorder[idx]!=pv)
                idx++;

            parent->left = buildTree(inorder, starti, idx-1, postorder, startp, idx-1-starti+startp);
            parent->right = buildTree(inorder, idx+1, endi, postorder, idx-starti+startp, endp-1);

            return parent;
        }
    }

    static TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1); 
    }
};

int main()
{
    vector<int> inorder;    
    inorder.push_back(2);
    inorder.push_back(1);
    vector<int> postorder;    
    postorder.push_back(2);
    postorder.push_back(1);
    TreeNode* root = Solution::buildTree(inorder, postorder);
}
