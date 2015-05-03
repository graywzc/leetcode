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

    int vec2int(vector<int>& pn)
    {
        int res = 0;
        int i = 0;
        while(i < pn.size()) 
        {
            res = res*10;
            res += pn[i];
            i++;
        }

        return res;
    }
    void sn(TreeNode *nd, int &sum, vector<int> &pn)
    {
        if(nd->left == NULL && nd->right == NULL) 
        {
            pn.push_back(nd->val); 
            int res = vec2int(pn);
            sum += res;
            pn.pop_back();
            return;
        }

        if (nd->left != NULL)
        {
            pn.push_back(nd->val);  
            sn(nd->left, sum, pn); 
            pn.pop_back();
        }

        if (nd->right != NULL)
        {
            pn.push_back(nd->val);  
            sn(nd->right, sum, pn); 
            pn.pop_back();
        }

        return;
    }
    
    int sumNumbers(TreeNode *root) {
        int sum = 0;

        if(root == NULL)
            return sum;

        vector<int> pn;
        
        sn(root, sum, pn);

        return sum;
    }
};
