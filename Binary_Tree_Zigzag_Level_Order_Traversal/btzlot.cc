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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;        
        if(NULL == root)
            return res;
        queue<TreeNode*> q0;
        queue<TreeNode*> q1;

        q0.push(root);

        queue<TreeNode*> *currq = &q0;
        queue<TreeNode*> *nextq = &q1;

        vector<int> temp;
        int flag = 0;
        while(currq->size()>0)
        {
            TreeNode* nd = currq->front();
            currq->pop();
            temp.push_back(nd->val); 
            if(nd->left) nextq->push(nd->left);
            if(nd->right) nextq->push(nd->right);
            if(currq->size() == 0)
            {
                queue<TreeNode*> *qtemp = currq; 
                currq = nextq;
                nextq = qtemp;
                if(flag)
                    reverse(temp.begin(), temp.end());
                res.push_back(temp);
                flag = 1-flag;
                temp.clear();
            }
        }

        return res;
    }
};
