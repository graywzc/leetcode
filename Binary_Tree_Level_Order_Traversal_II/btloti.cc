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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;        
        queue<TreeNode*> q0;
        queue<TreeNode*> q1;

        if(root == NULL)
            return res;
        
        q0.push(root);
        int flag = 0;

        while(1)
        {
            queue<TreeNode*> *pq0 = (flag==0)?(&q0):(&q1);
            queue<TreeNode*> *pq1 = (flag==1)?(&q0):(&q1);

            if(pq0->size() == 0) break;
            res.push_back(vector<int>());

            while(pq0->size()>0)
            {
                TreeNode *nd = pq0->front(); 
                pq0->pop();
                res.back().push_back(nd->val); 
                if(nd->left) pq1->push(nd->left);
                if(nd->right) pq1->push(nd->right);
            }

            flag = 1-flag;
        }

        reverse(res.begin(), res.end());

        return res;

    }
};
