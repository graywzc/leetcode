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

    TreeNode *build_bst(const vector<int> &num, int start, int end)
    {
        if(start>end) 
            return NULL;
        int mid = (start+end)/2;
        TreeNode *nd = new TreeNode(num[mid]);
        nd->left = build_bst(num,start, mid-1);
        nd->right = build_bst(num, mid+1, end);
        return nd;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build_bst(num, 0, num.size()-1); 
    }
};
