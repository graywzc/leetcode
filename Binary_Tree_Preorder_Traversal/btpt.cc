// iterative version
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

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *nd = root;  
        
        while(1)
        {
            while(nd != NULL)
            {
                res.push_back(nd->val); 
                st.push(nd);
                nd = nd->left;
            }

            if(st.size() == 0)
                break;

            nd = st.top();
            st.pop();
            nd = nd->right;
        }

        return res;
    }
};
