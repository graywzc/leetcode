// iterative
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<pair<TreeNode*, int>> st;

        TreeNode* nd = root;



        while(1)
        {
            while(nd!=NULL)
            {
                st.push(pair<TreeNode*, int>(nd, 0)); 
                nd = nd->left;
            }

            if(st.size() == 0)
                break;

            if(st.top().second == 0)
            {
                nd = st.top().first;
                nd = nd->right;
                st.top().second = 1;
            }
            else
            {
                nd = st.top().first; 
                res.push_back(nd->val); 
                st.pop();
                nd = NULL;
            }
        }

        return res;

    }
};
