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
    vector<TreeNode *> recurGenTree(int start, int end)
    {
        vector<TreeNode *> res;
        if(start > end) 
        {
            res.push_back(NULL); 
            return res;
        }
        int i = start;
        while(i<=end)
        {
            vector<TreeNode*> vleft = recurGenTree(start, i-1);
            vector<TreeNode*> vright = recurGenTree(i+1, end);
            for(int j = 0; j < vleft.size(); j++)
            {
                for(int k = 0; k < vright.size(); k++)  
                {
                    TreeNode* nd = new TreeNode(i); 
                    nd->left = vleft[j];
                    nd->right = vright[k];
                    res.push_back(nd);
                }
            }
            i++; 
        }
    }
    
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;    
        res = recurGenTree(1,n);
        return res;
    }
};
