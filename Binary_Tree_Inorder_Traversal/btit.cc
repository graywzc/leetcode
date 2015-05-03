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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;           
        TreeNode *nd = root;
        vector<int> results;

        while(1)
        {
            while(nd != NULL)
            {
                st.push(nd); 
                nd = nd->left;
            }

            if(st.size() == 0) break;

            nd = st.top();
            st.pop();
            results.push_back(nd->val);

            nd = nd->right;
        }

        return results;
        
    }
};
