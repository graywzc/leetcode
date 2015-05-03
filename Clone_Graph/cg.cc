/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// my solution, doesn't pass
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
            return NULL;
        
        queue<UndirectedGraphNode*> q;    
        q.push(node);

        while(q.size()>0)
        {
            UndirectedGraphNode *v = q.front();  
            q.pop();

            UndirectedGraphNode *copy = new UndirectedGraphNode(v->label);
            v->neighbors.push_back(copy);

            for(int i = 0; i < v->neighbors.size()-1; i++)
            {
                UndirectedGraphNode *nb = v->neighbors[i]; 
                UndirectedGraphNode *nbnb = nb->neighbors.back();
                if(nbnb->neighbors.size()!=0)
                {
                    q.push(nb); 
                }
            }
            
        }

        q.push(node);
        while(q.size()>0)
        {
            UndirectedGraphNode *v = q.front();  
            q.pop();

            UndirectedGraphNode *copy = v->neighbors.back();
            for(int i = 0; i < v->neighbors.size()-1; i++)
            {
                UndirectedGraphNode *nb = v->neighbors[i]; 
                copy->neighbors.push_back(nb->neighbors.back());
            }
            for(int i = 0; i < v->neighbors.size()-1; i++)
            {
                UndirectedGraphNode *nb = v->neighbors[i]; 
                UndirectedGraphNode *nbnb = nb->neighbors.back(); 
                if(nbnb->neighbors.size()==0)
                {
                    q.push(nb); 
                }
            }
        }

        return node->neighbors.back();
    }
};
